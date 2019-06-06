#include "BinaryTree.h"

BinaryTree::BinaryTree()
{

}

BinaryTree::BinaryTree(int nT, BinaryTreeNode* node){
    T=nT;
    t=(nT-1)/2;
    root=node;
    printString="";
}

BinaryTree::~BinaryTree(){

}

void BinaryTree::Merge(){

}

void BinaryTree::Sort(){

}

void BinaryTree::Delete(){

}

void BinaryTree::split(){
    int orden=0,grado=0;
    BinaryTreeNode* izq=new BinaryTreeNode(orden);
    BinaryTreeNode* der=new BinaryTreeNode(orden);
    if(root->getChildrenAt(0)!=NULL){
        for (int i=0;i<grado+1;i++) {
            izq->setParent(root->getChildrenAt(i));

        }
    }


}
