#ifndef NODE_H_
#define NODE_H_
class Node{ 
private:
	int data;
	Node * both;
	inline Node * node_xor(Node * a, Node * b) const;
public:
	Node(const int &);
	void add(const int &);
	const int get(int &);
};
#endif
