#include "language.hpp"

std::string CodeLine::repr() {
  std::string res;

  if (type == CodeLineType::Code_Declaration) {
    res = lhs + " " + rhs + ";";
    if (comment != "") {
      res = res + "\t//" + comment;
    }
    return res;
  }

  if (type == CodeLineType::Code_Assignment) {
    res = res + lhs + " = ";
  }
  res = res + rhs + ";";

  if (comment != "") {
    res = res + "\t//" + comment;
  }

  return res;
}

CodeLine::CodeLine(CodeLineType type, std::string lhs, std::string rhs,
                   std::string comment)
    : type(type), lhs(lhs), rhs(rhs), comment(comment) {}
