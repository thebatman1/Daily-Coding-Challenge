#include "node.h"
#include <iostream>
#include <utility>

using namespace std;

int count_unival_subtrees(Node *);
pair<int, bool> count_unival_subtrees_helper(Node *);

int main(void) {
    Node * root = new Node(0, new Node(1), new Node(0, new Node(1, new Node(1), new Node(1)), new Node(0)));
    cout << "Inorder traversal of the tree is: ";
    root -> traverse();
    cout << "\nNo of Unival Subtrees are: " << count_unival_subtrees(root) << "\n";
    return 0;
}


int count_unival_subtrees(Node * root) {
   return count_unival_subtrees_helper(root).first; 
}


pair<int, bool> count_unival_subtrees_helper(Node * root) {
    if (root == nullptr) {
        return make_pair(0, true); 
    }
    pair<int, bool> left_count_is_unival_pair = count_unival_subtrees_helper(root -> get_left());
    pair<int, bool> right_count_is_unival_pair = count_unival_subtrees_helper(root -> get_right());
    int left_count = left_count_is_unival_pair.first;
    int right_count = right_count_is_unival_pair.first;
    int total_count = left_count + right_count;
    bool is_left_unival = left_count_is_unival_pair.second;
    bool is_right_unival = right_count_is_unival_pair.second;
    if (is_left_unival && is_right_unival) {
        if ((root -> get_left() != nullptr) && (root -> get_value() != root -> get_left() -> get_value())) {
            return make_pair(total_count, false); 
        }
        if ((root -> get_right() != nullptr) && (root -> get_value() != root -> get_right() -> get_value())) {
            return make_pair(total_count, false); 
        }
        return make_pair(total_count + 1, true);
    }
    return make_pair(total_count, false);
}
