#ifndef PC_Register
#define PC_Register

class PC{
    private:
    int pc;

    public:
    PC();
    int GetPC();
    void SetPC(int NewPC); 
};

#endif //PC_Register