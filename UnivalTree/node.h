#ifndef NODE_H_
#define NODE_H_
class Node{
private:
    int data;
    Node * left, * right;
    void traverse_helper(Node *);
public:
    Node(int);
    Node(int, Node *, Node *);
    void traverse();
    Node * get_left() { return this -> left; }
    Node * get_right() { return this -> right; }
    int get_value() { return this -> data; }
};
#endif
