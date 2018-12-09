#include "node.h"
#include <iostream>
#include <cstdint>


inline Node * Node::node_xor(Node * node1, Node * node2) const {
	return (Node *) ((uintptr_t) (node1) ^ (uintptr_t) (node2));
}


Node::Node(const int & val) {
	this -> data = val;
	this -> both = nullptr;
}


void Node::add(const int & data) {
	Node * cur = this;
	Node * prev = nullptr;
	Node * next;
	while (cur != nullptr) {
		next = node_xor(prev, cur -> both);
		prev = cur;
		cur = next;
	}
	cur = new Node(data);
	cur->both = node_xor(prev, nullptr);
}


const int Node::get(int & k) {
	Node * cur = this;
	Node * prev = nullptr;
	Node * next;
	if (k == 0) {
		return cur -> data;	
	}
	while (cur != nullptr && k != 0) {
		next = node_xor(prev, cur -> both);
		prev = cur;
		cur = next;
		k--;
	}
	return prev -> data;
}
