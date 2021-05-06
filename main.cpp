#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <iostream>

/// Different Splits
/// Language - C, C++, Rust, Swift
/// Architecture - x86, Arm, RISC
/// Input type - assembly code (at&t or intel), byte code

/// Desired interface -
/// auto decompiler = Decompiler(L_SWIFT, M_X86);

// For starters, no enums, only strings

// Starting to right, I feel rust would have been better because of powerful enums

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

long stolhex(std::string s, size_t *pos)
{
    long val;
    int offset;
    if (s[0] == '-')
    {
        offset = 3;
        val = -1;
    }
    else
    {
        offset = 2;
        val = 1;
    }
    val = val * std::stol(s.substr(offset), pos, 16);
    if (pos)
        *pos = *pos + offset;
    return val;
}

class x86Instruction {
public:
    
    std::string mnemonic;
    std::vector<std::string> operands;

    x86Instruction(std::string s) {
        boost::trim(s);
        if (s == "") {
            return;
        }
        size_t pos = s.find(" ");
        mnemonic = s.substr(0, pos);

        std::string operands_string = boost::trim_copy(s.substr(pos));
        boost::split(operands, operands_string, [](char c){ return c == ',';});
        
    }
};

class x86Function {
public:
    // symbolic value of what is stored in registers right now
    std::map<std::string, std::string> registers;

    std::map<int, std::string> local_variables;

    std::vector<std::string> code;

    std::string parse_source(std::string operand)
    {
        std::string source;
        if (operand[0] == '$') 
        {
            // Immediate value
            int val = stolhex(operand.substr(1), nullptr);
            source = std::to_string(val);
        }
        else if (operand[0] == '%')
        {
            // register source
            source = "r_" + operand.substr(1);
        }
        else
        {
            size_t pos;
            int offset = stolhex(operand, &pos);
            if (operand.substr(pos) == "(%rbp)")
            {
                if (offset < 0) {
                    // local var
                    if (local_variables.find(offset) == local_variables.end()) {
                        // new local var
                        source = "local_" + std::to_string(local_variables.size());
                        local_variables[offset] = source;
                        source = RED + source + RESET;
                    }
                    else {
                        source = local_variables[offset];
                    }
                }
                else {
                    // argument
                }
            }
        }
        return source;
    }

    std::string parse_dest(std::string operand)
    {
        std::string dest;
        if (operand[0] == '%') 
        {
            // register dest
            dest = "r_" + operand.substr(1);
        }
        else 
        {
            size_t pos;
            int offset = stolhex(operand, &pos);
            if (operand.substr(pos) == "(%rbp)")
            {
                if (offset < 0) {
                    // local var
                    if (local_variables.find(offset) == local_variables.end()) {
                        // new local var
                        dest = "local_" + std::to_string(local_variables.size());
                        local_variables[offset] = dest;
                        dest = "int " + dest;
                    }
                    else {
                        dest = local_variables[offset];
                    }
                }
                else {
                    // argument
                }
            }
        }
        return dest;
    }

    std::string parse_op(std::string mnemonic)
    {
        std::string op;
        if (mnemonic == "imul")
        {
            op = "*";
        }
        else if (mnemonic == "add")
        {
            op = "+";
        }
        else if (mnemonic == "shl")
        {
            op = "<<";
        }
        return op;
    }

    void eat(x86Instruction instr) {
        if (instr.mnemonic == "movl" || instr.mnemonic == "mov") {
            // movl source, dest
            // step 1: destination
            std::string dest = parse_dest(instr.operands[1]);

            // step 2: source
            std::string source = parse_source(instr.operands[0]);

            code.push_back(dest + " = " + source + ";");
        }
        else if (instr.mnemonic == "imul" || instr.mnemonic == "add" || instr.mnemonic == "shl")
        {
            size_t num_operands = instr.operands.size();

            // step 1: dest
            size_t dest_operand_idx = instr.operands.size() - 1;
            std::string dest = parse_dest(instr.operands[dest_operand_idx]);

            std::string source2 = parse_source(instr.operands[dest_operand_idx - 1]);
            // step 2: source 1
            std::string source1;
            if (num_operands == 2)
            {
                source1 = dest;
            }
            else
            {
                source1 = parse_source(instr.operands[dest_operand_idx - 2]);
            }
            
            std::string bin_op = parse_op(instr.mnemonic);
            code.push_back(dest + " = " + source1 + " " + bin_op + " " + source2);
        }
        return;
    }

};

int main()
{
    std::string assembly = "\
        movl   $0x0,-0x4(%rbp)\n\
        movl   $0x5,-0x8(%rbp)\n\
        imul   $0x7,-0x8(%rbp),%ecx\n\
        add    $0x20,%ecx\n\
        mov    %ecx,-0xc(%rbp)\n\
        mov    -0xc(%rbp),%ecx\n\
        shl    $0x3,%ecx\n\
        add    $0x2,%ecx\n\
        mov    %ecx,-0x10(%rbp)\n";
    
    std::cout << assembly;

    std::vector<std::string> lines;
    boost::split(lines, assembly, [](char c){ return c == '\n';});

    x86Function func;
    for(std::string line: lines) {
        x86Instruction instr = x86Instruction(line);
        func.eat(instr);
    }

    for(std::string code: func.code) {
        std::cout << code << std::endl;
    }

    return 0;
}
