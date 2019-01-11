#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

string longest_k_length_substring(const string &, const int &);

int main(void) {
    string s;
    int k;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "The longest substring with k distinct characters is: "
         << longest_k_length_substring(s, k) << "\n";
    return 0;
}

const string longest_k_length_substring(const string & s, const int & k) {
    int len = s.length();
    unordered_map<char, int> char_count;
    int no_of_unique_chars = 0;
    for (char ch: s) {
        if (char_count.find(ch) == char_count.end()) {
            no_of_unique_chars++; 
        } 
        char_count[ch]++; 
    }
    assert(no_of_unique_chars >= k);
    int max_length = 0, cur_length = 0;
    int max_start = 0, max_size = 0;
    char_count.clear();
    for (int i = 0; i < len; ++i) {
        int temp = char_count.size(); 
        if (char_count.find(s[i]) == char_count.end()) {
            cur_length++;
        } 
        if (char_count.size() > k) {
            max_length = max(max_length, cur_length);
            cur_length = 0;
        }
    }
}
