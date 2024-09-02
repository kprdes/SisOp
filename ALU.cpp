#include "ALU.hpp"

void ALU::setOperation(int id){
    this->operation = id;
}

void ALU::Alu_Control(){
    switch(this->operation){
        case 1: //Instruction ADD
            ALU_ADD();
        break;
        case 2: //Instruction INC
            ALU_INC();
        break;
        case 3: //Instruction DEC
            ALU_DEC();
        break;
    }
}



void ALU::ALU_ADD(){
    if(D3 == 0 && D4 == 0){
        *ac += D1; 
    }
    else if(D4 == 0){
        *ac = D1;
        *D1 += D3;
    }
    else{
        D4 = D1 + D3;
    }
}

void ALU::ALU_INC(){
    int d3 = loadD3();
    d3 += 1;
    setD3(d3);
}

void ALU::ALU_DEC(){
    int d3 = loadD3();
    d3 = d3 - 1;
    setD3(d3);
}



