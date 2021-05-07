#include "instruction.hpp"

Instruction::Instruction(std::string s) {
    // remove comment
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