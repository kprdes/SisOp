#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "ALU.hpp"
#include "CPU.hpp"

class ControlUnit{
    private:

    char* intructions[ 9 ] = {"SET", "LDR", "ADD", "INC", "DEC", "STR", "SHW", "PAUSE", "END"};
    void set();
    void ldr();
    
    

    public:
    ControlUnit();
    void decode(char* instruction); //void porque los resultados van en la memoria o los registros
    
};

#endif