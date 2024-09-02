#include "ICR.hpp"

int getICR(){
    int tmp = this->currentInstruction;
    return tmp;
}
void setICR(int newIcr){
    this->currentInstruction = newIcr;
}