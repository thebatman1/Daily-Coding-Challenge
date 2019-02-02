#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_set>
#include <unordered_map>
class Graph{
private:
	std::unordered_map<char, std::unordered_set<char>> adj;
public:
    /** Method to add an edge between two nodes of the graph
      * @param src : Character from which the edge is to be drawn
      * @param des : Character to which the edge is to be drawn
      */
	void add_edge(const char &, const char &);


    /** Method to find a path from one character to another
      * @param word : A string whose presence in the matrix is to be checked
      * @returns    : The truth value of whether the string is present or not
      */
	bool find_path(const std::string &);
};
#endif
