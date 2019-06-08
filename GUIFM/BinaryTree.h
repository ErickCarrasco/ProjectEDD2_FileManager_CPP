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
    BinaryTree(int);
    BinaryTreeNode* getRoot();
    void sort(BinaryTreeNode*);
    void insert(Key*);
    void split(BinaryTreeNode*);
    void remove(string);
    void merge(BinaryTreeNode*);
    BinaryTreeNode* getLeaf(BinaryTreeNode*, string);
    int findIndex(BinaryTreeNode*, string);
    BinaryTreeNode* findNode(BinaryTreeNode*, string);
    void printPrev();
    void printPrev(BinaryTreeNode*);
    string getString();

    /*
=======
    BinaryTree(int, BinaryTreeNode*);
    void Merge();
    void Delete();
    void Sort();
    void split();
    ~BinaryTree();
>>>>>>> 247022649874dce1a955106aea5c889f7769d2ab
*/
};

#endif // BINARYTREE_H
