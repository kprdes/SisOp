#include "Register.hpp"
using namespace std;

Register::Register(){}

Register::Register(int n){
    value = n;
}

Register::Register(string s){
    instruction = s;
}

int Register::getValue(){
    return this->value; 
}
void Register::setValue(int n){
    this->value = n;
}

string Register::getInstruction(){
    return this->instruction;
}

void Register::setInstruction(string s){
    this->instruction = s;
}
