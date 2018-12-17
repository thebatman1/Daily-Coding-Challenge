#include <iostream>
#include <cstring>

using namespace std;

int number_ways(string);
int number_ways_helper(string, int, int[]);

int main(void) {
    string message;
    cout << "Enter the encoded message: ";
    cin >> message;
    cout << "The no of ways it can be decoded is: " << number_ways(message) << "\n";
    return 0;
}


int number_ways(string s) {
    int memo[s.length() + 1];
    memset(memo, -1, sizeof(memo));
    return number_ways_helper(s, s.length(), memo);
}


int number_ways_helper(string s, int k, int memo[]) {
    // If there is an empty string, only one way to decode it: "" -> ""
    if (k == 0) {
        return 1; 
    }
    // If the string starts with 0, return 0 as invalid
    int i = s.length() - k;
    if (s[i] == '0') {
        return 0; 
    }
    // If the result is already present in memo
    if (memo[k] != -1) {
        return memo[k];
    }
    int result = number_ways_helper(s, k - 1, memo);
    const char * str = (s.substr(i, 2)).c_str();
    if (k >= 2 && atoi(str) <= 26) {
        result += number_ways_helper(s, k - 2, memo);   
    }
    memo[k] = result;
    return result;
}
