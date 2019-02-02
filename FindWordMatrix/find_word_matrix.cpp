#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;


/** Function to generate a graph of alphabets
 * 	@param chars : A 2-d matrix of characters
 * 	@returns     : A graph object
 */
Graph create_graph(const vector<vector<char>> &);


/** Function to find the word among the matrix
 *  @param chars : A 2-d matrix of characters
 *  @param word  : A string to be found in the matrix
 *  @returns     : A boolean value to show if the word is present or not
 */
bool find_word(const vector<vector<char>> &, const string &);


int main(void) {
    int n, m;
    cout << "Enter the no of rows: ";
    cin >> n;
	cout << "Enter the no of columns: ";
	cin >> m;
	cout << "Enter the characters: ";
	vector<vector<char>> chars;
	for (int i = 0; i < n; ++i) {
		vector<char> temp;
		for (int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;	
			temp.push_back(ch);
		}	
		chars.push_back(temp);
	}
	string word;
	cout << "Enter the word to be searched!";
	cin >> word;
	if (find_word(chars, word)) {
        cout << "Found!\n"; 
    } else {
        cout << "Not Found!\n"; 
    }
    return 0;
}


Graph create_graph(const vector<vector<char>> & chars) {
	Graph g;
	const int n = chars.size();
	const int m = chars.at(0).size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			g.add_edge(chars[i][j], chars[i + 1][j]);	
            if (j != m - 1)
                g.add_edge(chars[i][j], chars[i][j + 1]);	
		}	
	}
    for (int j = 0; j < m - 1; ++j) {
        g.add_edge(chars[n - 1][j], chars[n - 1][j + 1]); 
    }
	return g;
}


bool find_word(const vector<vector<char>> & chars, const string & word) {
	return (create_graph(chars)).find_path(word);
}

