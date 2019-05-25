#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h
#include <vector>
#include <string>

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