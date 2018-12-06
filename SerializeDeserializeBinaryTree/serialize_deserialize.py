#!/usr/bin/env python3.6


MARKER = '-1'
DELIM = '|'


class Node(object):
    """ A class that defines a node in a Binary Tree """
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(root, ans=""):
    """ A function that serializes the Binary Tree to a string """
    if not root:
        return ans + MARKER + DELIM

    return (ans + root.val + DELIM + serialize(root.left, ans) +
            serialize(root.right, ans))


def deserialize(serialized):
    """ A function that deserialize the given string to Binary Tree """
    nodes = serialized[:-1].split('|')
    root = None
    return deserialize_helper(root, nodes)[0]


def deserialize_helper(root, nodes, i=0):
    """ A helper function to deserialize the string to a Binary Tree """
    node = nodes[i]
    if node == MARKER:
        return None, i
    root = Node(node)
    root.left, k = deserialize_helper(root.left, nodes, i + 1)
    root.right, k = deserialize_helper(root.right, nodes, k + 1)
    return root, k


def preorder_traversal(root):
    """ Function to perform preorder traversal """
    if not root:
        return
    print(root.val + " ")
    preorder_traversal(root.left)
    preorder_traversal(root.right)


def main():
    """ The main function """
    node = Node('root',
                Node('left',
                     Node('left.left')),
                Node('right'))
    print(deserialize(serialize(node)).left.left.val == 'left.left')


if __name__ == '__main__':
    main()
