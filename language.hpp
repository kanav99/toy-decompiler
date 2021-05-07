#ifndef DECOMPILER_LANG_HPP
#define DECOMPILER_LANG_HPP

#include <string>

class CodeLine {
  /// whether the line is an assignment or just an expression
  bool assignment;
  /// LHS of a line, empty for `assigment == false`
  std::string lhs;
  /// RHS of a line
  std::string rhs;
  /// Additional Comment
  std::string comment;

public:
  std::string repr();
  CodeLine(bool assignment, std::string lhs, std::string rhs,
           std::string comment);
};

#endif
