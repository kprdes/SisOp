#ifndef CPU_HPP
#define CPU_HPP

#include "Register.hpp"
#include "ControlUnit.hpp"
#include "ALU.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;



class CPU{
    private:
    vector<Register> registers;
    Register mar, mdr, icr, pc, accum;
    Register memory[ 100 ];
    ControlUnit controlUnit;
    ALU alu;

    public:
    CPU();
    void fetch();
    int decode();
    void excecute();
    void printRegisters();
    void loadInstructions(vector<string>& instructions);
    void init();
    vector<string> ReadInfo(string& filename); 
    
    // Getters
    Register getMAR() { return mar; }
    Register getMDR() { return mdr; }
    Register getICR() { return icr; }
    Register getPC() { return pc; }
    Register getMemory(int index) { return memory[index]; }

    // Setters
    void setMAR(Register value) { mar = value; }
    void setMDR(Register value) { mdr = value; }
    void setICR(Register value) { icr = value; }
    void setPC(Register value) { pc = value; }
    void setAccum(Register value) { accum = value; }
    void setMemory(int index, Register value) { memory[index] = value; }
};

#endif //CPU_HPP