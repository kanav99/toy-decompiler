#include "function.hpp"

std::string Function::parse_source(Instruction instr, size_t operand_index)
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
                if (arguments.find(offset) == arguments.end()) {
                    // new local var
                    source = "arg_" + std::to_string(arguments.size() + 6);
                    arguments[offset] = source;
                }
                else {
                    source = local_variables[offset];
                }
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

std::string Function::parse_dest(Instruction instr, size_t operand_index)
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
                if (arguments.find(offset) == arguments.end()) {
                    // new local var
                    dest = "arg_" + std::to_string(arguments.size() + 6);
                    arguments[offset] = dest;
                }
                else {
                    dest = local_variables[offset];
                }
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

std::string Function::parse_op(std::string mnemonic)
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

void Function::eat(Instruction instr) {
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

Function::Function()
{
    registers["edi"] = "arg_0";
    registers["esi"] = "arg_1";
    registers["edx"] = "arg_2";
    registers["ecx"] = "arg_3";
    registers["r8d"] = "arg_4";
    registers["r9d"] = "arg_5";
}