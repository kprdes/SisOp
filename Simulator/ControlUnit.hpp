#ifndef CONTROLUNIT_HPP
#define CONTROLUNIT_HPP

#include "Register.hpp"
#include "ALU.hpp"
//#include "CPU.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class ControlUnit{
    private:
      string instruction;
      Register* mar;
      Register* mdr;
      Register* icr;
      Register* accum;
      ALU* alu;
      Register* memory;
      map<string, int> opcode;
    public:
      ControlUnit();
      ControlUnit(Register* i_mar, Register* i_mdr, Register* i_icr, Register* i_accum, ALU* i_alu, Register* i_memory)
  : mar(i_mar), mdr(i_mdr), icr(i_icr), accum(i_accum), alu(i_alu){
        memory = i_memory;
        opcode[ "SET" ] = 0;
        opcode[ "LDR" ] = 1;
        opcode[ "ADD" ] = 2;
        opcode[ "INC" ] = 3;
        opcode[ "DEC" ] = 4;
        opcode[ "STR" ] = 5;
        opcode[ "SHW" ] = 6;
        opcode[ "PAUSE" ] = 7;
        opcode[ "END" ] = 8;
      };
      int decode();
      string getInstruction();
      Register* getMAR() {
        return mar;
      }
      Register* getMDR() {
        return mdr;
      }
      Register* getICR() {
        return icr;
      }
      Register* getAccum() {
        return accum;
      }
};

#endif //CONTROLUNIT_HPP