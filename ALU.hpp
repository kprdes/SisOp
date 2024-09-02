#ifndef ALU_H
#define ALU_H
#include "PC.HPP"
#include "MAR.HPP"
#include "AC.HPP"
#include <string>
#include <iostream>


using namespace std;

class ALU{
    private:
    MAR* mar;
    PC* pc;
    AC* ac;
    int operation(int id);
    public:
    ALU();
    void setOperation(int id);
    void Alu_Control();
    void ALU_ADD();
    void ALU_INC();
    void ALU_DEC();
};

#endif //ALU_H
