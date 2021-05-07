#ifndef DECOMPILER_LANG_HPP
#define DECOMPILER_LANG_HPP

#include <string>

enum CodeLineType {
  Code_Assignment,
  Code_Expression,
  Code_Declaration,
};

class CodeLine {
  /// whether the line is an assignment or just an expression
  CodeLineType type;
  /// LHS of a line, empty for `Code_Expression`, variable type for
  /// `Code_Declaration`
  std::string lhs;
  /// RHS of a line, variable name for `Code_Declaration`
  std::string rhs;
  /// Additional Comment
  std::string comment;

public:
  std::string repr();
  CodeLine(CodeLineType type, std::string lhs, std::string rhs,
           std::string comment);
};

#endif
