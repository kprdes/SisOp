#ifndef ALU_HPP
#define ALU_HPP
#include <iostream>

class ALU{
  private:
    int a;
    int b;
    int result;
    int aluOp;
    void add();
    void inc();
    void dec();
  public:
    ALU();
    void operate();
    void setA(int i_a){
        a = i_a;
    }
    void setB(int i_b){
        b = i_b;
    }
    void setAluOp(int i_aluOp){
        aluOp = i_aluOp;
    }
    int getResult(){
        return result;
    }
};


#endif //ALU_HPP