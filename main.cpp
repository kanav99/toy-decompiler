#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <streambuf>

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

void print_vec(std::vector<uint8_t> v)
{
    for(auto i: v)
    {
        std::cout << std::hex << (int)i;
        std::cout << " ";
    }
    std::cout << std::endl;
}

class x86Instruction {
public:
    
    std::string mnemonic;
    std::vector<std::string> operands;
    std::vector<uint8_t> bytes;
    uint64_t instr_address;
    size_t size;

    x86Instruction(std::string s) {
        // remove comment
        std::cout << s << std::endl;
        size_t com = s.find('#');
        if (com != std::string::npos)
        {
            s = s.substr(0, com);
        }

        boost::trim(s);
        
        if (s == "") {
            return;
        }
        size_t pos;

        pos = s.find(":");
        instr_address = std::stol(s.substr(0, pos), nullptr, 16);

        pos += 1;
        while(true)
        {
            while(s[pos] == ' ' || s[pos] == '\t')
            {
                pos += 1;
            }
            if (s[pos + 2] == ' ' || s[pos + 2] == '\t')
            {
                // std::cout << s.substr(pos, 2) << " ";
                try {
                    uint8_t val = std::stol(s.substr(pos, 2), nullptr, 16);
                    bytes.push_back(val);
                    pos += 3;
                }
                catch(...) {
                    break;
                }
            }
            else {
                break;
            }
        }

        s = s.substr(pos);
        pos = s.find(" ");
        mnemonic = s.substr(0, pos);

        std::string operands_string = boost::trim_copy(s.substr(pos));
        boost::split(operands, operands_string, [](char c){ return c == ',';});
    }

    uint64_t get_rip()
    {
        return instr_address + bytes.size();
    }
};

class x86Function {
public:
    // symbolic value of what is stored in registers right now
    std::map<std::string, std::string> registers;

    std::map<int, std::string> local_variables;
    std::map<int, std::string> global_variables;
    std::map<int, std::string> heap_variables;

    std::vector<std::string> code;

    std::string parse_source(x86Instruction instr, size_t operand_index)
    {
        std::string operand = instr.operands[operand_index];
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
            source = "(" + registers[operand.substr(1)] + ")";
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
                        code.push_back("int " + source + ";"); 
                    }
                    else {
                        source = local_variables[offset];
                    }
                }
                else {
                    // argument
                }
            }
            else if (operand.substr(pos) == "(%rip)")
            {
                uint64_t addr = instr.get_rip() + offset;
                if (global_variables.find(addr) == global_variables.end()) {
                    // new global var
                    source = "global_" + std::to_string(global_variables.size());
                    global_variables[addr] = source;
                }
                else {
                    source = global_variables[addr];
                }
            }
        }
        return source;
    }

    std::string parse_dest(x86Instruction instr, size_t operand_index)
    {
        std::string operand = instr.operands[operand_index];
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
            else if (operand.substr(pos) == "(%rip)")
            {
                uint64_t addr = instr.get_rip() + offset;
                if (global_variables.find(addr) == global_variables.end()) {
                    // new global var
                    dest = "global_" + std::to_string(global_variables.size());
                    global_variables[addr] = dest;
                }
                else {
                    dest = global_variables[addr];
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
            std::string dest = parse_dest(instr, 1);

            // step 2: source
            std::string source = parse_source(instr, 0);

            if (dest[0] == 'r' && dest[1] == '_' )
            {
                registers[dest.substr(2)] = source;
            }
            else
            {
                code.push_back(dest + " = " + source + ";");
            }
        }
        else if (instr.mnemonic == "imul" || instr.mnemonic == "add" || instr.mnemonic == "shl")
        {
            size_t num_operands = instr.operands.size();

            // step 1: dest
            size_t dest_operand_idx = instr.operands.size() - 1;

            std::string source2 = parse_source(instr, dest_operand_idx - 1);
            // step 2: source 1
            std::string source1;
            if (num_operands == 2)
            {
                source1 = parse_source(instr, dest_operand_idx);
            }
            else
            {
                source1 = parse_source(instr, dest_operand_idx - 2);
            }

            std::string dest = parse_dest(instr, dest_operand_idx);
            
            std::string bin_op = parse_op(instr.mnemonic);

            if (dest[0] == 'r' && dest[1] == '_' )
            {
                registers[dest.substr(2)] = source1 + " " + bin_op + " " + source2;
            }
            else
            {
                code.push_back(dest + " = " + source1 + " " + bin_op + " " + source2 + ";");
            }
        }
        return;
    }

};

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
