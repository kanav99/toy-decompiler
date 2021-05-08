#include "architecture.hpp"

// Code specific to x86-64 ISA

/// converts an instruction mnemonic into a binary operator, if possible
std::string parse_op(std::string mnemonic) {
  std::string op;
  if (mnemonic == "imul") {
    op = "*";
  } else if (mnemonic == "add") {
    op = "+";
  } else if (mnemonic == "shl") {
    op = "<<";
  }
  return op;
}

RegisterSymbolicValue::RegisterSymbolicValue(RegisterMap* p, std::string r) : parent(p), reg(r) {}

RegisterSymbolicValue::operator std::string()
{
  RegisterSetMode currentMode, mode;
  std::string res;

  if (reg == "rax")
  {
    res = parent -> rax;
    currentMode = parent -> mode_rax;
  }
  else if (reg == "eax")
  {
    res = parent -> rax;
    currentMode = parent -> mode_rax;
  }
  else if (reg == "ax")
  {
    res = parent -> rax;
    currentMode = parent -> mode_rax;
  }
  else if (reg == "al")
  {
    res = parent -> rax;
    currentMode = parent -> mode_rax;
  }
  else if (reg == "rbx")
  {
    res = parent -> rbx;
    currentMode = parent -> mode_rbx;
  }
  else if (reg == "ebx")
  {
    res = parent -> rbx;
    currentMode = parent -> mode_rbx;
  }
  else if (reg == "bx")
  {
    res = parent -> rbx;
    currentMode = parent -> mode_rbx;
  }
  else if (reg == "bl")
  {
    res = parent -> rbx;
    currentMode = parent -> mode_rbx;
  }
  else if (reg == "rcx")
  {
    res = parent -> rcx;
    currentMode = parent -> mode_rcx;
  }
  else if (reg == "ecx")
  {
    res = parent -> rcx;
    currentMode = parent -> mode_rcx;
  }
  else if (reg == "cx")
  {
    res = parent -> rcx;
    currentMode = parent -> mode_rcx;
  }
  else if (reg == "cl")
  {
    res = parent -> rcx;
    currentMode = parent -> mode_rcx;
  }
  else if (reg == "rdx")
  {
    res = parent -> rdx;
    currentMode = parent -> mode_rdx;
  }
  else if (reg == "edx")
  {
    res = parent -> rdx;
    currentMode = parent -> mode_rdx;
  }
  else if (reg == "dx")
  {
    res = parent -> rdx;
    currentMode = parent -> mode_rdx;
  }
  else if (reg == "dl")
  {
    res = parent -> rdx;
    currentMode = parent -> mode_rdx;
  }
  else if (reg == "rsi")
  {
    res = parent -> rsi;
    currentMode = parent -> mode_rsi;
  }
  else if (reg == "esi")
  {
    res = parent -> rsi;
    currentMode = parent -> mode_rsi;
  }
  else if (reg == "si")
  {
    res = parent -> rsi;
    currentMode = parent -> mode_rsi;
  }
  else if (reg == "sil")
  {
    res = parent -> rsi;
    currentMode = parent -> mode_rsi;
  }
  else if (reg == "rdi")
  {
    res = parent -> rdi;
    currentMode = parent -> mode_rdi;
  }
  else if (reg == "edi")
  {
    res = parent -> rdi;
    currentMode = parent -> mode_rdi;
  }
  else if (reg == "di")
  {
    res = parent -> rdi;
    currentMode = parent -> mode_rdi;
  }
  else if (reg == "dil")
  {
    res = parent -> rdi;
    currentMode = parent -> mode_rdi;
  }
  else if (reg == "rsp")
  {
    res = parent -> rsp;
    currentMode = parent -> mode_rsp;
  }
  else if (reg == "esp")
  {
    res = parent -> rsp;
    currentMode = parent -> mode_rsp;
  }
  else if (reg == "sp")
  {
    res = parent -> rsp;
    currentMode = parent -> mode_rsp;
  }
  else if (reg == "spl")
  {
    res = parent -> rsp;
    currentMode = parent -> mode_rsp;
  }
  else if (reg == "rbp")
  {
    res = parent -> rbp;
    currentMode = parent -> mode_rbp;
  }
  else if (reg == "ebp")
  {
    res = parent -> rbp;
    currentMode = parent -> mode_rbp;
  }
  else if (reg == "bp")
  {
    res = parent -> rbp;
    currentMode = parent -> mode_rbp;
  }
  else if (reg == "bpl")
  {
    res = parent -> rbp;
    currentMode = parent -> mode_rbp;
  }
  else if (reg == "r8")
  {
    res = parent -> r8;
    currentMode = parent -> mode_r8;
  }
  else if (reg == "r8d")
  {
    res = parent -> r8;
    currentMode = parent -> mode_r8;
  }
  else if (reg == "r8w")
  {
    res = parent -> r8;
    currentMode = parent -> mode_r8;
  }
  else if (reg == "r8b")
  {
    res = parent -> r8;
    currentMode = parent -> mode_r8;
  }
  else if (reg == "r9")
  {
    res = parent -> r9;
    currentMode = parent -> mode_r9;
  }
  else if (reg == "r9d")
  {
    res = parent -> r9;
    currentMode = parent -> mode_r9;
  }
  else if (reg == "r9w")
  {
    res = parent -> r9;
    currentMode = parent -> mode_r9;
  }
  else if (reg == "r9b")
  {
    res = parent -> r9;
    currentMode = parent -> mode_r9;
  }
  else if (reg == "r10")
  {
    res = parent -> r10;
    currentMode = parent -> mode_r10;
  }
  else if (reg == "r10d")
  {
    res = parent -> r10;
    currentMode = parent -> mode_r10;
  }
  else if (reg == "r10w")
  {
    res = parent -> r10;
    currentMode = parent -> mode_r10;
  }
  else if (reg == "r10b")
  {
    res = parent -> r10;
    currentMode = parent -> mode_r10;
  }
  else if (reg == "r11")
  {
    res = parent -> r11;
    currentMode = parent -> mode_r11;
  }
  else if (reg == "r11d")
  {
    res = parent -> r11;
    currentMode = parent -> mode_r11;
  }
  else if (reg == "r11w")
  {
    res = parent -> r11;
    currentMode = parent -> mode_r11;
  }
  else if (reg == "r11b")
  {
    res = parent -> r11;
    currentMode = parent -> mode_r11;
  }
  else if (reg == "r12")
  {
    res = parent -> r12;
    currentMode = parent -> mode_r12;
  }
  else if (reg == "r12d")
  {
    res = parent -> r12;
    currentMode = parent -> mode_r12;
  }
  else if (reg == "r12w")
  {
    res = parent -> r12;
    currentMode = parent -> mode_r12;
  }
  else if (reg == "r12b")
  {
    res = parent -> r12;
    currentMode = parent -> mode_r12;
  }
  else if (reg == "r13")
  {
    res = parent -> r13;
    currentMode = parent -> mode_r13;
  }
  else if (reg == "r13d")
  {
    res = parent -> r13;
    currentMode = parent -> mode_r13;
  }
  else if (reg == "r13w")
  {
    res = parent -> r13;
    currentMode = parent -> mode_r13;
  }
  else if (reg == "r13b")
  {
    res = parent -> r13;
    currentMode = parent -> mode_r13;
  }
  else if (reg == "r14")
  {
    res = parent -> r14;
    currentMode = parent -> mode_r14;
  }
  else if (reg == "r14d")
  {
    res = parent -> r14;
    currentMode = parent -> mode_r14;
  }
  else if (reg == "r14w")
  {
    res = parent -> r14;
    currentMode = parent -> mode_r14;
  }
  else if (reg == "r14b")
  {
    res = parent -> r14;
    currentMode = parent -> mode_r14;
  }
  else if (reg == "r15")
  {
    res = parent -> r15;
    currentMode = parent -> mode_r15;
  }
  else if (reg == "r15d")
  {
    res = parent -> r15;
    currentMode = parent -> mode_r15;
  }
  else if (reg == "r15w")
  {
    res = parent -> r15;
    currentMode = parent -> mode_r15;
  }
  else if (reg == "r15b")
  {
    res = parent -> r15;
    currentMode = parent -> mode_r15;
  }
  else
  {
    throw "wrong lol";
  }

  size_t len = reg.size();
  char first_char = reg[0];
  char last_char = reg[len - 1];

  if (first_char == 'r' && last_char != 'd' && last_char != 'w' && last_char != 'b')
  {
    if (last_char == 'd')
    {
      mode = Mode4;
    }
    else if (last_char == 'w')
    {
      mode = Mode2;
    }
    else if (last_char == 'b')
    {
      mode = Mode1;
    }
    else
    {
      mode = Mode8;
    }
  }
  else if (first_char == 'e')
  {
    mode = Mode4;
  }
  else if (last_char == 'l')
  {
    mode = Mode1;
  }
  else
  {
    mode = Mode2;
  }

  if (mode != currentMode)
  {
    res = ")" + res;
    res = modeCast[mode] + res;
    res = "(" + res;
  }

  return res;
}

std::string& RegisterSymbolicValue::operator=(const std::string& value)
{

  if (reg == "rax")
  {
    parent -> rax = value;
    parent -> mode_rax = Mode8;
  }
  else if (reg == "eax")
  {
    parent -> rax = value;
    parent -> mode_rax = Mode4;
  }
  else if (reg == "ax")
  {
    parent -> rax = value;
    parent -> mode_rax = Mode2;
  }
  else if (reg == "al")
  {
    parent -> rax = value;
    parent -> mode_rax = Mode1;
  }
  else if (reg == "rbx")
  {
    parent -> rbx = value;
    parent -> mode_rbx = Mode8;
  }
  else if (reg == "ebx")
  {
    parent -> rbx = value;
    parent -> mode_rbx = Mode4;
  }
  else if (reg == "bx")
  {
    parent -> rbx = value;
    parent -> mode_rbx = Mode2;
  }
  else if (reg == "bl")
  {
    parent -> rbx = value;
    parent -> mode_rbx = Mode1;
  }
  else if (reg == "rcx")
  {
    parent -> rcx = value;
    parent -> mode_rcx = Mode8;
  }
  else if (reg == "ecx")
  {
    parent -> rcx = value;
    parent -> mode_rcx = Mode4;
  }
  else if (reg == "cx")
  {
    parent -> rcx = value;
    parent -> mode_rcx = Mode2;
  }
  else if (reg == "cl")
  {
    parent -> rcx = value;
    parent -> mode_rcx = Mode1;
  }
  else if (reg == "rdx")
  {
    parent -> rdx = value;
    parent -> mode_rdx = Mode8;
  }
  else if (reg == "edx")
  {
    parent -> rdx = value;
    parent -> mode_rdx = Mode4;
  }
  else if (reg == "dx")
  {
    parent -> rdx = value;
    parent -> mode_rdx = Mode2;
  }
  else if (reg == "dl")
  {
    parent -> rdx = value;
    parent -> mode_rdx = Mode1;
  }
  else if (reg == "rsi")
  {
    parent -> rsi = value;
    parent -> mode_rsi = Mode8;
  }
  else if (reg == "esi")
  {
    parent -> rsi = value;
    parent -> mode_rsi = Mode4;
  }
  else if (reg == "si")
  {
    parent -> rsi = value;
    parent -> mode_rsi = Mode2;
  }
  else if (reg == "sil")
  {
    parent -> rsi = value;
    parent -> mode_rsi = Mode1;
  }
  else if (reg == "rdi")
  {
    parent -> rdi = value;
    parent -> mode_rdi = Mode8;
  }
  else if (reg == "edi")
  {
    parent -> rdi = value;
    parent -> mode_rdi = Mode4;
  }
  else if (reg == "di")
  {
    parent -> rdi = value;
    parent -> mode_rdi = Mode2;
  }
  else if (reg == "dil")
  {
    parent -> rdi = value;
    parent -> mode_rdi = Mode1;
  }
  else if (reg == "rsp")
  {
    parent -> rsp = value;
    parent -> mode_rsp = Mode8;
  }
  else if (reg == "esp")
  {
    parent -> rsp = value;
    parent -> mode_rsp = Mode4;
  }
  else if (reg == "sp")
  {
    parent -> rsp = value;
    parent -> mode_rsp = Mode2;
  }
  else if (reg == "spl")
  {
    parent -> rsp = value;
    parent -> mode_rsp = Mode1;
  }
  else if (reg == "rbp")
  {
    parent -> rbp = value;
    parent -> mode_rbp = Mode8;
  }
  else if (reg == "ebp")
  {
    parent -> rbp = value;
    parent -> mode_rbp = Mode4;
  }
  else if (reg == "bp")
  {
    parent -> rbp = value;
    parent -> mode_rbp = Mode2;
  }
  else if (reg == "bpl")
  {
    parent -> rbp = value;
    parent -> mode_rbp = Mode1;
  }
  else if (reg == "r8")
  {
    parent -> r8 = value;
    parent -> mode_r8 = Mode8;
  }
  else if (reg == "r8d")
  {
    parent -> r8 = value;
    parent -> mode_r8 = Mode4;
  }
  else if (reg == "r8w")
  {
    parent -> r8 = value;
    parent -> mode_r8 = Mode2;
  }
  else if (reg == "r8b")
  {
    parent -> r8 = value;
    parent -> mode_r8 = Mode1;
  }
  else if (reg == "r9")
  {
    parent -> r9 = value;
    parent -> mode_r9 = Mode8;
  }
  else if (reg == "r9d")
  {
    parent -> r9 = value;
    parent -> mode_r9 = Mode4;
  }
  else if (reg == "r9w")
  {
    parent -> r9 = value;
    parent -> mode_r9 = Mode2;
  }
  else if (reg == "r9b")
  {
    parent -> r9 = value;
    parent -> mode_r9 = Mode1;
  }
  else if (reg == "r10")
  {
    parent -> r10 = value;
    parent -> mode_r10 = Mode8;
  }
  else if (reg == "r10d")
  {
    parent -> r10 = value;
    parent -> mode_r10 = Mode4;
  }
  else if (reg == "r10w")
  {
    parent -> r10 = value;
    parent -> mode_r10 = Mode2;
  }
  else if (reg == "r10b")
  {
    parent -> r10 = value;
    parent -> mode_r10 = Mode1;
  }
  else if (reg == "r11")
  {
    parent -> r11 = value;
    parent -> mode_r11 = Mode8;
  }
  else if (reg == "r11d")
  {
    parent -> r11 = value;
    parent -> mode_r11 = Mode4;
  }
  else if (reg == "r11w")
  {
    parent -> r11 = value;
    parent -> mode_r11 = Mode2;
  }
  else if (reg == "r11b")
  {
    parent -> r11 = value;
    parent -> mode_r11 = Mode1;
  }
  else if (reg == "r12")
  {
    parent -> r12 = value;
    parent -> mode_r12 = Mode8;
  }
  else if (reg == "r12d")
  {
    parent -> r12 = value;
    parent -> mode_r12 = Mode4;
  }
  else if (reg == "r12w")
  {
    parent -> r12 = value;
    parent -> mode_r12 = Mode2;
  }
  else if (reg == "r12b")
  {
    parent -> r12 = value;
    parent -> mode_r12 = Mode1;
  }
  else if (reg == "r13")
  {
    parent -> r13 = value;
    parent -> mode_r13 = Mode8;
  }
  else if (reg == "r13d")
  {
    parent -> r13 = value;
    parent -> mode_r13 = Mode4;
  }
  else if (reg == "r13w")
  {
    parent -> r13 = value;
    parent -> mode_r13 = Mode2;
  }
  else if (reg == "r13b")
  {
    parent -> r13 = value;
    parent -> mode_r13 = Mode1;
  }
  else if (reg == "r14")
  {
    parent -> r14 = value;
    parent -> mode_r14 = Mode8;
  }
  else if (reg == "r14d")
  {
    parent -> r14 = value;
    parent -> mode_r14 = Mode4;
  }
  else if (reg == "r14w")
  {
    parent -> r14 = value;
    parent -> mode_r14 = Mode2;
  }
  else if (reg == "r14b")
  {
    parent -> r14 = value;
    parent -> mode_r14 = Mode1;
  }
  else if (reg == "r15")
  {
    parent -> r15 = value;
    parent -> mode_r15 = Mode8;
  }
  else if (reg == "r15d")
  {
    parent -> r15 = value;
    parent -> mode_r15 = Mode4;
  }
  else if (reg == "r15w")
  {
    parent -> r15 = value;
    parent -> mode_r15 = Mode2;
  }
  else if (reg == "r15b")
  {
    parent -> r15 = value;
    parent -> mode_r15 = Mode1;
  }
  else
  {
    throw "wrong lol";
  }

}

RegisterSymbolicValue RegisterMap::operator[](std::string reg)
{
  return RegisterSymbolicValue(this, reg);
}

