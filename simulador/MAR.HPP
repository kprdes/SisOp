#ifndef MAR_H
#define MAR_H
#include <iostream>
#include <string>
#include "ALU.hpp"

using namespace std;
class MAR{
    private:
    int memoryAddress;
    int* D1;
    int* D2;
    int* D3;
    

    public:
    MAR();
    int getMAR();
    void setMAR(int mar);
    void interpretate_instruction(string& instruction);
    int loadD1();
    int loadD2();
    int loadD3();
    void setD1(int tmp);
    void setD2(int tmp);
    void setD3(int tmp);
};

#endif //MAR_H