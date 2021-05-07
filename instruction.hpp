#ifndef DECOMPILER_INSTRUCTION_HPP
#define DECOMPILER_INSTRUCTION_HPP

#include <string>
#include <vector>

class Instruction {
public:
  /// String mnemonic. Example: "movl"
  std::string mnemonic;
  /// String operands. Example: {"-0x8(%rbp)", "%rdi"}
  std::vector<std::string> operands;
  /// String representation of instruction
  std::string repr;
  /// Vector of bytes for the instruction.
  std::vector<uint8_t> bytes;
  // Address of instruction
  uint64_t instr_address;
  // Number of bytes for the instruction
  size_t size;

  /// Constructor for an Instruction that takes as input a line from disassembly
  /// output of `objdump` command. Assumes AT&T syntax. Example input:
  /// `100003f3f:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi`
  Instruction(std::string s);

  /// TODO: Instruction constructed from bytes
  Instruction(uint8_t *);

  /// Return RIP register value for the current instruction.
  uint64_t get_rip() { return instr_address + bytes.size(); }
};

#endif
