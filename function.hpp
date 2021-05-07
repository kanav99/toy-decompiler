#ifndef DECOMPILER_FUNCTION_HPP
#define DECOMPILER_FUNCTION_HPP

#include <string>
#include <map>
#include <vector>
#include "instruction.hpp"
#include "utils.hpp"
#include "language.hpp"

class Function {
public:
    /// Function name
    std::string name;
    /// Function address
    uint64_t address;
    /// Ordered instructions
    std::vector<Instruction> instructions;
    /// symbolic value of what is stored in registers right now
    std::map<std::string, std::string> registers;

    /// Map of RBP offset to the name of local variable. Offset < 0
    std::map<int, std::string> local_variables;
    /// Map of address to the name of global variable
    std::map<int, std::string> global_variables;
    /// Map of address to the name of heap variable
    std::map<int, std::string> heap_variables;
    /// Map of RBP offset to the name of stack argument. Offset > 0
    std::map<int, std::string> arguments;

    /// Decompiled C-Code of function
    std::vector<CodeLine> code;

    /// Parses the source operands of an instruction and outputs a string representaion of it's symbolic value.
    std::string parse_source(Instruction instr, size_t operand_index);
    /// Parses the destination operand of an instruction and outputs a string representaion of it's symbolic value.
    std::string parse_dest(Instruction instr, size_t operand_index);

    void eat(Instruction instr);

    void print_code();

    Function();

};

#endif