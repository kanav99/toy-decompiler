#include "language.hpp"

std::string CodeLine::repr()
{
    std::string res;
    if (assignment)
    {
        res = res + lhs + " = "; 
    }
    res = res + rhs + ";";
    
    if (comment != "")
    {
        res = res + " //" + comment;
    }
    
    return res;
}

CodeLine::CodeLine(bool assignment, std::string lhs, std::string rhs, std::string comment)
    : assignment(assignment), lhs(lhs), rhs(rhs), comment(comment)
{
    
}
