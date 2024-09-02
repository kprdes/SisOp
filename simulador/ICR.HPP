#ifndef ICR_H
#define ICR_H
#include <stdio.h>

class ICR{

    private:
    int currentInstruction;

    public:
    ICR();
    int getICR();
    void setICR(int NewIcr);
};

#endif //ICR_H