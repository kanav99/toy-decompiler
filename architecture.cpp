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
