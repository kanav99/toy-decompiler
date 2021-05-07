#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <streambuf>

#include "instruction.hpp"
#include "function.hpp"

/// Different Splits
/// Language - C, C++, Rust, Swift
/// Architecture - x86, Arm, RISC
/// Input type - assembly code (at&t or intel), byte code

/// Currently - assembly code in at&t, x86, C (aiming for Swift)

/// Desired interface -
/// auto decompiler = Decompiler(L_SWIFT, M_X86);

/// For starters, no enums, only strings

/// Starting to write, I feel rust would have been better because of powerful enums

/// Features -
/// Single function
/// Local and global variables, including consts
/// basic arithmetic operations

int main()
{
    std::ifstream f("assembly.s");
    std::string assembly;
    f.seekg(0, std::ios::end); 
    assembly.reserve(f.tellg());
    f.seekg(0, std::ios::beg);
    assembly.assign((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());

    std::vector<std::string> lines;
    boost::split(lines, assembly, [](char c){ return c == '\n';});

    Function func;
    for(std::string line: lines) {
        Instruction instr = Instruction(line);
        func.eat(instr);
    }

    for(std::string code: func.code) {
        std::cout << code << std::endl;
    }

    return 0;
}
