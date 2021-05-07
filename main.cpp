#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <streambuf>
#include <string>
#include <vector>

#include "function.hpp"
#include "instruction.hpp"

int main() {
  std::ifstream f("assembly.s");
  std::string assembly;
  f.seekg(0, std::ios::end);
  assembly.reserve(f.tellg());
  f.seekg(0, std::ios::beg);
  assembly.assign((std::istreambuf_iterator<char>(f)),
                  std::istreambuf_iterator<char>());

  std::vector<std::string> lines;
  boost::split(lines, assembly, [](char c) { return c == '\n'; });

  Function func;
  for (std::string line : lines) {
    Instruction instr = Instruction(line);
    func.eat(instr);
  }

  func.print_code();

  return 0;
}
