#ifndef DECOMPILER_INSTRUCTION_HPP
#define DECOMPILER_INSTRUCTION_HPP

#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>

class Instruction {
public:
    
    std::string mnemonic;
    std::vector<std::string> operands;
    std::vector<uint8_t> bytes;
    uint64_t instr_address;
    size_t size;

    Instruction(std::string s);

    uint64_t get_rip()
    {
        return instr_address + bytes.size();
    }
};

#endif
