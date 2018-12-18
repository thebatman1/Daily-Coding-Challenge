#ifndef SIMPLE_DICTIONARY_H_
#define SIMPLE_DICTIONARY_H_
#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
class SimpleDictionary:public Dictionary{
private:
    bool starts_with(const std::string & s, const std::string & prefix) {
        return (s.rfind(prefix, 0) == 0);
    }
public:
    SimpleDictionary(const std::string &);
    std::vector<std::string> get_words_with_prefix(const std::string &);
};
#endif
