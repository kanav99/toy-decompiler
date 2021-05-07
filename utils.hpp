#ifndef DECOMPILER_UTILS_HPP
#define DECOMPILER_UTILS_HPP

#include <string>
#include <vector>
#include <iostream>

// Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

long stolhex(std::string s, size_t *pos);

void print_vec(std::vector<uint8_t> v);

#endif