#include "simple_dictionary.h"
#include <cstdlib>

SimpleDictionary::SimpleDictionary(const std::string & filename) {
    std::ifstream infile;
    std::string s;
    try {
        infile.open(filename); 
        while (getline(infile, s)) {
            words.push_back(s); 
        }   
        std::sort(words.begin(), words.end());
        infile.close();
    } catch(std::exception &e) {
        std::cout << "Something went wrong while reading the file. Exiting.....\n";
        exit(EXIT_FAILURE);
    }
}


std::vector<std::string> SimpleDictionary::get_words_with_prefix(const std::string & prefix) {
    int start = 0;
    int end = words.size() - 1;
    int len = end;
    int mid;
    bool flag = false;
    std::vector<std::string> results;
    while (start < end) {
        mid = (start + end) / 2;
        std::string s = words.at(mid);
        int c = (starts_with(s, prefix)) ? 0 : prefix.compare(s);
        if (c > 0) {
            start = mid + 1;
        } else if (c < 0) {
            end = mid - 1;
        } else if (c == 0) {
            flag = true;
            break;
        }
    }
    std::string t;
    if (flag) {
        int i = mid + 1, j = mid;
        while (i <= len && starts_with((t = words.at(i)), prefix)) {
            results.push_back(t);
            ++i;
        }
        while (j >= 0 && starts_with((t = words.at(j)), prefix)) {
            results.push_back(t);
            --j;
        }
    }
    std::sort(results.begin(), results.end());
    return results;
}
