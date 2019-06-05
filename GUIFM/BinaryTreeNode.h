#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h
#include "Key.h"
#include "linkedlist.h"
#include <vector>
#include <string>

using namespace std;

class BinaryTreeNode{
	private:
        BinaryTreeNode* parent = NULL;
        List<Key*>* keys;
        List<BinaryTreeNode*>* children;
        int T;
        int t;
	public:
        //Constructors
		BinaryTreeNode();
		BinaryTreeNode(int);

        //Getters
        List<Key*>* getKeys();
        Key* getKeyAt(int);
        BinaryTreeNode* getParent();
        int getT();
        int getMinimum();
        List<BinaryTreeNode*>* getChildren();
        BinaryTreeNode* getChildrenAt(int);

        //Setter
        void setParent(BinaryTreeNode*);

        //Others
        bool isLeaf();
        string toString();
        void addChild(BinaryTreeNode*);
        void removeLastChild();
		~BinaryTreeNode();
	
};

#endif
