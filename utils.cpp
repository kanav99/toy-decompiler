#include "utils.hpp"

long stolhex(std::string s, size_t *pos)
{
    long val;
    int offset;
    if (s[0] == '-')
    {
        offset = 3;
        val = -1;
    }
    else
    {
        offset = 2;
        val = 1;
    }
    val = val * std::stol(s.substr(offset), pos, 16);
    if (pos)
        *pos = *pos + offset;
    return val;
}

void print_vec(std::vector<uint8_t> v)
{
    for(auto i: v)
    {
        std::cout << std::hex << (int)i;
        std::cout << " ";
    }
    std::cout << std::endl;
}