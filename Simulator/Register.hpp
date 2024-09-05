#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <iostream>
#include <string>

using namespace std;

class Register{
    private:
        int value;
        string instruction;
    public:
        Register();
        Register(int n);
        Register(string s);
        int getValue();
        void setValue(int n);
        string getInstruction();
        void setInstruction(string s);
};

#endif //REGISTER_HPP