#include "graph.h"


void Graph::add_edge(const char & src, const char & des) {
	if (adj.find(src) == adj.end()) {
		std::unordered_set<char> temp;
		adj.insert(make_pair(src, temp));	
	} else {
		adj[src].insert(des);
	}
}


bool Graph::find_path(const std::string & word) {
	// If the first letter does not exist in the map,
	// it does not exist in the matrix either
	if (adj.find(word[0]) == adj.end()) {
		return false;	
	}

	const int n = word.length();
	// Otherwise, keep traversing the graph until we get the last letter of the word
	// or we find that no more of the word exists in the matrix
	for (int i = 1; i < n; ++i) {
		char prev = word[i - 1];
		char cur = word[i];
		if (adj[prev].find(word[i]) == adj[prev].end()) {
			return false;	
		}
	}
	return true;
}
