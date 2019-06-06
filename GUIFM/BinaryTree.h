#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryTreeNode.h"


class BinaryTree{
private:
    BinaryTreeNode* root = NULL;
    int T;
    int t;
    string printString;

public:
    BinaryTree();
    BinaryTree(int, BinaryTreeNode*);
    void Merge();
    void Delete();
    void Sort();
    void split();
    ~BinaryTree();
};

#endif // BINARYTREE_H
