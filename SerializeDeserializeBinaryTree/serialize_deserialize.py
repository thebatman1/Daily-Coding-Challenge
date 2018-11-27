#!/usr/bin/env python3.6


class Node(object):
    """ A class that defines a node in a Binary Tree """
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
