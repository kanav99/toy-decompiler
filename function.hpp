#ifndef DECOMPILER_FUNCTION_HPP
#define DECOMPILER_FUNCTION_HPP

#include <string>
#include <map>
#include <vector>
#include "instruction.hpp"
#include "utils.hpp"

class Function {
public:
    std::string name;
    uint64_t function_address;

    // symbolic value of what is stored in registers right now
    std::map<std::string, std::string> registers;

    // Maps for different types of variables
    std::map<int, std::string> local_variables;
    std::map<int, std::string> global_variables;
    std::map<int, std::string> heap_variables;
    std::map<int, std::string> arguments;

    // Decompiled C-Code
    std::vector<std::string> code;

    std::string parse_source(Instruction instr, size_t operand_index);

    std::string parse_dest(Instruction instr, size_t operand_index);

    std::string parse_op(std::string mnemonic);

    void eat(Instruction instr);

    Function();

};

#endif