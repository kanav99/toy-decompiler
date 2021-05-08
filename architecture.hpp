#ifndef DECOMPILER_ARCH_HPP
#define DECOMPILER_ARCH_HPP

#include <string>

std::string parse_op(std::string mnemonic);

enum RegisterSetMode {
    Mode8,
    Mode4,
    Mode2,
    Mode1,
};

char modeCast[][9] = {
    "uint64_t",
    "uint32_t",
    "uint16_t",
    "uint8_t",
};

class RegisterSymbolicValue {
public:
    RegisterMap* parent;
    std::string reg;
    
    operator std::string();
    std::string& operator=(const std::string& value);

    RegisterSymbolicValue(RegisterMap* parent, std::string reg);
};

class RegisterMap {
public:
    std::string rax;
    std::string rbx;
    std::string rcx;
    std::string rdx;
    std::string rsi;
    std::string rdi;
    std::string rsp;
    std::string rbp;
    std::string r8;
    std::string r9;
    std::string r10;
    std::string r11;
    std::string r12;
    std::string r13;
    std::string r14;
    std::string r15;

    RegisterSetMode mode_rax;
    RegisterSetMode mode_rbx;
    RegisterSetMode mode_rcx;
    RegisterSetMode mode_rdx;
    RegisterSetMode mode_rsi;
    RegisterSetMode mode_rdi;
    RegisterSetMode mode_rsp;
    RegisterSetMode mode_rbp;
    RegisterSetMode mode_r8;
    RegisterSetMode mode_r9;
    RegisterSetMode mode_r10;
    RegisterSetMode mode_r11;
    RegisterSetMode mode_r12;
    RegisterSetMode mode_r13;
    RegisterSetMode mode_r14;
    RegisterSetMode mode_r15;

    RegisterSymbolicValue operator[](std::string reg);
};

#endif
