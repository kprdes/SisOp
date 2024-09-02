#include "MAR.hpp"
MAR::MAR(){};

int MAR::getMAR(){
    int tmp = this->memoryAddress;
    return tmp;
}

void MAR::setMAR(int mar){
    this->memoryAddress = mar;
}

void MAR::interpretate_instruction(string& instruction) {
        istringstream iss(instruction);
        string op;
        string arg1, arg2, arg3;

        iss >> op >> arg1 >> arg2 >> arg3;

        if (op == "ADD") {
            D1 = stoi(arg1);  // Convertimos el primer argumento a entero y lo asignamos a D1

            if (arg2 == "NULL") {
                D3 = 0;  // Representamos NULL como 0
            } else {
                D3 = stoi(arg2);  // Convertimos el segundo argumento si no es NULL
            }

            if (arg3 == "NULL") {
                D4 = 0;  // Representamos NULL como 0
            } else {
                D4 = stoi(arg3);  // Convertimos el tercer argumento si no es NULL
            }

            ALU_ADD();  // Llamamos a la función correspondiente para ejecutar la operación
        } else {
            std::cerr << "Operación no soportada: " << op << std::endl;
        }
    }
};
