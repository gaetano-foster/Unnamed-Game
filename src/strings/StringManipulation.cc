#include "StringManipulation.hh"
#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>
#include <cstring>

std::vector<std::string> str_split(std::string str, std::string sep) {
    char *cstr = const_cast<char*>(str.c_str());
    char *current;
    std::vector<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != nullptr) {
        arr.push_back(current);
        current = strtok(nullptr, sep.c_str());
    }
    return arr;
}