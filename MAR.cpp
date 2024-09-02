#include "MAR.hpp"
MAR::MAR(){};

int MAR::getMAR(){
    int tmp = this->memoryAddress;
    return tmp;
}

void MAR::setMAR(int mar){
    this->memoryAddress = mar;
}

int MAR::loadD1(){
    return this->*D1;
}
int MAR::loadD2(){
    return this->*D2;
}
int MAR::loadD3(){
    return this->*D3;
}
void setD1(int tmp){
    this->*D1 = tmp;
}
void setD2(int tmp){
    this->*D2 = tmp;
}
void setD3(int tmp){
    this->*D3 = tmp;
}


void MAR::interpretate_instruction(string& instruction) {
        istringstream iss(instruction);
        string op;
        string Reg1, Reg2, Reg3;

        iss >> op >> Reg1 >> Reg2 >> Reg3;

        if (op == "ADD") {
            setOperation(1);
            this->*D1 = stoi(Reg1);  
            if (Reg2 == "NULL") {
                this->*D3 = 0; 
            } else {
                this->*D3 = stoi(Reg2);
            }

            if (Reg3 == "NULL") {
                this->*D4 = 0;
            } else {
                this->*D4 = stoi(Reg3);
            }

        }
        if (op == "INC") {
            setOperation(2);
            this->*D3 = stoi(Reg1);
        }
        if (op == "DEC") {
            setOperation(3);
            this->*D3 = stoi(Reg1);  
        }

}
