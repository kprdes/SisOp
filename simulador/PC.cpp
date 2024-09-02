#include "PC.hpp"

int PC::GetPC(){
    int tmp = this->pc;
    return tmp;
}

void PC::SetPC(int NewPC){
    this->pc = NewPC;
} 