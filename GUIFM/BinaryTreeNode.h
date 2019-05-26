#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h
#include "Key.h"
#include "linkedlist.h"
#include <vector>
#include <string>

using namespace std;

class BinaryTreeNode{
	private:
		BinaryTreeNode* padre = NULL;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
	public:
		BinaryTreeNode();
		BinaryTreeNode(int);
		~BinaryTreeNode();
	
};

#endif
