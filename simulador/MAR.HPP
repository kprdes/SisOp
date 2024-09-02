#ifndef MAR_H
#define MAR_H
#include <iostream>
#include <string>

using namespace std;
class MAR{
    private:
    int memoryAddress;

    public:
    MAR();
    int getMAR();
    void setMAR(int mar);
    void interpretate_instruction(string& instruction);
};

#endif //MAR_H