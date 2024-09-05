#include "ControlUnit.hpp"

ControlUnit::ControlUnit() {
  opcode[ "SET" ] = 0;
  opcode[ "LDR" ] = 1;
  opcode[ "ADD" ] = 2;
  opcode[ "INC" ] = 3;
  opcode[ "DEC" ] = 4;
  opcode[ "STR" ] = 5;
  opcode[ "SHW" ] = 6;
  opcode[ "PAUSE" ] = 7;
  opcode[ "END" ] = 8;
}

string ControlUnit::getInstruction(){
  return instruction;
}

int ControlUnit::decode() {
  instruction = this->getICR()->getInstruction();
  
  stringstream ss(instruction);
  string part;
  
  vector<string> parts;
  while (getline(ss, part, ' ')) {
    parts.push_back(part);
  }

  switch(opcode[ parts[ 0 ] ]){
    case 0:
      // SET
      mar->setValue(stoi(parts[ 1 ]));
      accum->setValue(stoi(parts[2]));
      mdr->setValue(accum->getValue());
      memory[ mar->getValue() ] = mdr->getValue();
      break;
    case 1:
      // LDR
      mar->setValue(stoi(parts[ 1 ]));
      mdr->setValue(memory[ mar->getValue() ].getValue());
      accum->setValue(mdr->getValue());
      break;
    case 2:
      // ADD
      if(parts[ 2 ] == "NULL"){
        //Case 1
        mar->setValue( stoi(parts[ 1 ]) );
        mdr->setValue( memory[ mar->getValue() ].getValue() );
        alu->setA(mdr->getValue());
        alu->setB( accum->getValue() );
        alu->setAluOp( 0 );
        alu->operate();
        accum->setValue(alu->getResult());
      }
      else if (parts[ 2 ] != "NULL" && parts[ 3 ] == "NULL") {
        //Case 2
        mar->setValue( stoi(parts[ 1 ]) );
        mdr->setValue( memory[ mar->getValue() ].getValue() );
        accum->setValue(mdr->getValue());
        mar->setValue( stoi(parts[ 2 ]) );
        mdr->setValue( memory[ mar->getValue() ].getValue() );
        alu->setA( accum->getValue() );
        alu->setB( mdr->getValue() );
        alu->setAluOp( 0 );
        alu->operate();
        accum->setValue(alu->getResult());
      }
      else{
        //Case 3
        mar->setValue( stoi(parts[ 1 ]) );
        mdr->setValue( memory[ mar->getValue() ].getValue() );
        accum->setValue(mdr->getValue());
        mar->setValue( stoi(parts[ 2 ]) );
        mdr->setValue( memory[ mar->getValue() ].getValue() );
        alu->setA( accum->getValue() );
        alu->setB( mdr->getValue() );
        alu->setAluOp( 0 );
        alu->operate();
        accum->setValue(alu->getResult());
        mdr->setValue(accum->getValue());
        mar->setValue( stoi(parts[ 3 ]) );
        memory[ mar->getValue() ].setValue(mdr->getValue());
      }
      break;
    case 3:
      // INC
      mar->setValue( stoi(parts[ 1 ]) );
      mdr->setValue(memory[ mar->getValue() ].getValue());
      alu->setA(mdr->getValue());
      alu->setAluOp( 1 );
      alu->operate();
      accum->setValue(alu->getResult());
      mdr->setValue(memory[ accum->getValue() ].getValue());
      memory[ mar->getValue() ].setValue(mdr->getValue());
      break;
    case 4:
      // DEC
      mar->setValue( stoi(parts[ 1 ]) );
      mdr->setValue(memory[ mar->getValue() ].getValue());
      alu->setA(mdr->getValue());
      alu->setAluOp( 2 );
      alu->operate();
      accum->setValue(alu->getResult());
      mdr->setValue(memory[ accum->getValue() ].getValue());
      memory[ mar->getValue() ].setValue(mdr->getValue());
      break;
    case 5:
      // STR
      mar->setValue( stoi(parts[ 1 ]));
      mdr->setValue(accum->getValue());
      memory[ mar->getValue() ] = mdr->getValue();
      break;
    case 6:
      // SHW
      if(parts[ 1 ] == "ACC"){
        cout << "ACC: " << accum->getValue() << endl;
      }
      else if(parts[ 1 ] == "MAR"){
        cout << "MAR: " << mar->getValue() << endl;
      }
      else if (parts[ 1 ] == "MDR"){
        cout << "MDR: " << mdr->getValue() << endl;
      }
      else if (parts[ 1 ] == "ICR"){
        cout << "ICR: " << icr->getInstruction() << endl;
      }
      else if(parts [ 1 ] == "UC"){
        cout << "UC: " << instruction << endl;
      }
      else{
        mar->setValue(stoi(parts[ 1 ]));
        cout << "Value in " << parts[ 1 ] << " = " << memory[ mar->getValue() ].getValue() << endl;
      }
      break;
    case 7:
      // PAUSE
      return 2;
      break;
    case 8:
      return -1;
      // END
      
      break;
    default:
      break;
  }
  return 0;
}