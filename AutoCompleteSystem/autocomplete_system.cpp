#include "simple_dictionary.h"

using namespace std;

int main(void) {
    Dictionary * dict = new SimpleDictionary("words.txt");
    string query;
    cout << "Enter the query string: ";
    cin >> query;
    vector<string> results = dict -> get_words_with_prefix(query);
    if (results.size() != 0) {
        for (auto x : results) {
            cout << x << "\n"; 
        }
    } else {
        cout << "No results found!\n";
    }
    return 0;
}

