#include "node.h"
#include <iostream>
#include <cstdint>


// Method to xor the address values of two nodes
inline Node * Node::node_xor(Node * node1, Node * node2) const {
	return (Node *) ((uintptr_t) (node1) ^ (uintptr_t) (node2));
}


// The Constructor
Node::Node(const int & val) {
	this -> data = val;
	this -> both = nullptr;
}


// Method to add a new node at the end of the linked list
void Node::add(const int & data) {
    Node * head = this;
	Node * cur = this;
	Node * prev = nullptr;
	Node * next;
    Node * prev_prev = nullptr;
    // Loop to the end of the linked list
	while (cur != nullptr) {
		next = node_xor(prev, cur -> both);
        if (prev_prev == nullptr && prev == head) { 
            prev_prev = prev;
        } else {
            prev_prev = prev; 
        }
		prev = cur;
		cur = next;
	}
	cur = new Node(data);
    if (prev != nullptr) {
        prev -> both = node_xor(prev_prev, cur);
    }
	cur->both = node_xor(prev, nullptr);
}


// Method to traverse the linked list
void Node::traverse() {
    Node * cur = this;
    Node * prev = nullptr;
    Node * next;
    while (cur != nullptr) {
        next = node_xor(prev, cur->both);
        std::cout << cur -> data << " ";
        prev = cur;
        cur = next;
    }
}


// Method to get traverse the linked list and get the data at the index
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
	return (cur != nullptr) ? cur -> data : -1;
}
