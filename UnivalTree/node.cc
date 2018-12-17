#include "node.h"
#include <iostream>


Node::Node(int data) {
    this -> data = data;
    this -> left = nullptr;
    this -> right = nullptr;
}


Node::Node(int data, Node * left, Node * right) {
    this -> data = data;
    this -> left = left;
    this -> right = right;
}


void Node::traverse() {
    traverse_helper(this);
}


void Node::traverse_helper(Node * root) {
    if (root == nullptr)
        return;
    traverse_helper(root -> left);
    std::cout << root -> data << " ";
    traverse_helper(root -> right);
}

