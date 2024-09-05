#include "ALU.hpp"

ALU::ALU() {}

void ALU::add() {
  result = a + b;
}
void ALU::inc() {
  result = a++;
}
void ALU::dec() {
  result = a--;
}

void ALU::operate(){
  switch(aluOp){
    case 0:
      add();
      break;
    case 1:
      inc();
      break;
    case 2:
      dec();
      break;
    default:
      break;
  }
}