#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <vector>
#include <string>
class Dictionary {
protected:
    std::vector<std::string> words;
public:
    virtual std::vector<std::string> get_words_with_prefix(const std::string &) = 0;
};
#endif
