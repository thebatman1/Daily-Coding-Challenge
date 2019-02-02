#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_set>
#include <unordered_map>
class Graph{
private:
	// No of vertices
	int V;
	std::unordered_map<char, std::unordered_set<char>> adj;
public:
	void add_edge(const char &, const char &);
	bool find_path(const std::string &);
};
#endif
