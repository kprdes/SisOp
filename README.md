
# CPU Simulation Project

## Table of Contents
- [Project Overview](#project-overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Classes Documentation](#classes-documentation)
  - [Register](#register)
  - [CPU](#cpu)
  - [ControlUnit](#controlunit)
  - [ALU](#alu)
- [Contributing](#contributing)
- [License](#license)

## Project Overview
This project is a simulation of a basic instruction cycle in C++. It includes core components such as a `Register`, `CPU`, `Control Unit`, and an `ALU` . The goal is to simulate the functionality of a CPU that fetches, decodes, and executes instructions from memory.

## Requirements
- C++11 or higher
- Standard C++ Libraries

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/kprdes/SisOp
   ```
2. Navigate to the project directory:
   ```bash
   cd simulador
   ```
3. Compile the project:
   ```bash
   gcc Register.cpp CPU.cpp ControlUnit.cpp ALU.cpp
   ```
4. Run the executable:
   ```bash
   a.exe
   ```

## Usage
1. The program starts in the CPU reading "Info.txt" which are the instructions to simulate the basic instruction cycle. At info.txt are all instructions, if you want to test the program there is a menu to chose which file you want to test.

2. The program support those instructions: 
- SET
- LDR
- ADD
- INC
- DEC
- STR
- SHW
- PAUSE
- END.

3. The program only support 3 NULL, the struct for write an instruction is: instruction D3 NULL NULL NULL
As can be seen the program might read 5 different things separete but the last or fourth NULL is not using.


## Classes Documentation

### Register

The `Register` class represents a general-purpose register in the CPU. It stores an integer value or an instruction string.

#### Public Methods:
- `Register()`: Default constructor that initializes the register with default values.
- `Register(int n)`: Constructor to initialize the register with an integer value.
- `Register(string s)`: Constructor to initialize the register with an instruction string.
- `int getValue()`: Returns the current integer value stored in the register.
- `void setValue(int n)`: Sets the value of the register to the given integer.
- `string getInstruction()`: Returns the current instruction string stored in the register.
- `void setInstruction(string s)`: Sets the instruction string for the register.

#### Example Usage:
```cpp
mar->setValue(stoi(parts[ 1 ]));
accum->setValue(stoi(parts[2]));
mdr->setValue(accum->getValue());
```
mar, accum, mdr are registers, parts[  1  ] is the first value of the instruction. In:
```cpp
ADD D3 NULL NULL NULL
```
parts[  1  ] is equal to D3
### CPU

The `CPU` class simulates a simple CPU that fetches, decodes, and executes instructions stored in memory. It contains multiple `Register` instances and interacts with the `ControlUnit` and `ALU`.

#### Public Methods:
- `CPU()`: Default constructor that initializes the CPU and its components.
- `void fetch()`: Fetches the next instruction to be executed.
- `void decode()`: Decodes the fetched instruction.
- `void execute()`: Executes the decoded instruction.
- `void printRegisters()`: Prints the current values of all registers.
- `void loadInstructions(vector<string>& instructions)`: Loads a list of instructions into the CPU's memory.
- `void init()`: Initializes the CPU for operation.
- `vector<string> ReadInfo(string& filename)`: Reads instructions from a file.

#### Getters and Setters:
- Getters for `MAR`, `MDR`, `ICR`, `PC`, `Accum`, and `Memory[]`.
- Setters for the same, allowing control over individual registers.

### ControlUnit

The `ControlUnit` class is responsible for decoding instructions and managing the control signals required to operate the CPU.

#### Public Methods:
- `ControlUnit()`: Default constructor that initializes the control unit.
- `ControlUnit(Register* mar, Register* mdr, Register* icr, Register* accum, int* aluOp, ALU* alu, Register** memory)`: Overloaded constructor for initializing with specific registers and ALU.
- `void decode()`: Decodes the current instruction stored in the `ICR` register.
- `string getInstruction()`: Returns the currently decoded instruction.
- Getters for `MAR`, `MDR`, `ICR`, `Accum`.


### ALU

The `ALU` is responsible for performing arithmetic operations like addition, increment, and decrement.

#### Public Methods:
- `ALU()`: Default constructor for the ALU.
- `ALU(Register* accum)`: Overloaded constructor that takes a reference to the accumulator register.
- `int operate()`: Executes the operation based on the opcode.
- `void setA(int a)`: Sets the value of operand A.
- `void setB(int b)`: Sets the value of operand B.

#### Private Methods:
- `void add()`: Performs the addition operation.
- `void inc()`: Increments the accumulator.
- `void dec()`: Decrements the accumulator.

