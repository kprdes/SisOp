#include "CPU.hpp"
CPU::CPU() {}

void CPU::init() {
  pc = Register(50);
  mar = Register();
  mdr = Register();
  icr = Register();
  accum = Register();
  controlUnit = ControlUnit(&mar, &mdr, &icr, &accum, &alu, memory);
}

void CPU::fetch() {
  mar.setValue(pc.getValue());
  mdr.setInstruction(memory[mar.getValue()].getInstruction());
  icr.setInstruction(mdr.getInstruction());
  pc.setValue(pc.getValue() + 1);
}

void CPU::printRegisters() {
  cout << "MAR: " << mar.getValue() << "\nMDR: " << mdr.getValue()
       << "\nICR: " << icr.getInstruction() << "\nACCUM: " << accum.getValue() << "\nPC: " << pc.getValue() << "\nControl Unit: " << controlUnit.getInstruction()<< endl;
}

void CPU::loadInstructions(vector<string>& instructions) {
    int i = 0;
    for (vector<string>::const_iterator it = instructions.begin(); it != instructions.end(); ++it) {
      memory[i + 50].setInstruction(*it);
      i++;
    }
}

int CPU::decode() { return controlUnit.decode(); }

vector<string> CPU::ReadInfo(string& filename) {
    vector<string> instructions;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error " << filename << endl;
        return instructions;
    }

    string line;
    while (getline(file, line)) {
        line.erase(line.find_last_not_of(" \n\r\t") + 1);
        if (!line.empty()) {
            size_t pos = 0;
            while ((pos = line.find('D', pos)) != string::npos) {
                if (pos > 0 && isdigit(line[pos + 1])) {
                    line.erase(pos, 1);
                } else {
                    ++pos;
                }
            }
            instructions.push_back(line);
        }
    }
    file.close();
    return instructions;
}

void CPU::excecute() {

}

int main() {
  CPU cpu;
  string filename;
  int choise;
  bool exit = 1;
  while (exit){
    cout << "Which document do you want to test?" << endl;
    cout << "1. File 1.\n2. File 2.\n3. File 3.\n4. Exit." << endl;
    cin >> choise;
    switch(choise){
      case 1:
        filename = "Info.txt";
        break;
      case 2:
      filename = "Info2.txt";
      break;
      case 3:
      filename = "Info3.txt";
      break;
      case 4:
        exit = 0;
        break;
      default:
        cout << "Invalid choise" << endl;
        filename = "Info.txt";
    } 
    vector<string> instructions = cpu.ReadInfo(filename);
    int n = 0, p = 0;
    cpu.loadInstructions(instructions);
    cpu.init();
    while(n != -1){
      cpu.fetch();
      n = cpu.decode();
      if(n == 2){
        cout<<"Show registers? \n1.Yes\n2.No\n";
        cin>>p;
        if(p == 1){
          cpu.printRegisters();
        }
        cout << "Press Enter to continue...\n\n";
        cin.ignore(1,' ');
        cin.get();

      }
    }
  }
  
  return 0;
}
