#include "BinaryTree.h"

BinaryTree::BinaryTree(){

}

BinaryTree::BinaryTree(int nT){
    root = new BinaryTreeNode(nT);
    T= nT;
    t=(nT-1)/2;

}

BinaryTreeNode* BinaryTree::getRoot(){
    return root;
}

void BinaryTree::sort(BinaryTreeNode* node){
    List<Key> temp;
    for (int i = 1; i<= node->getKeys()->size;i++) {
        temp.insert(*node->getKeyAt(i));
    }
    temp.sort();
    node->getKeys()->clear();
    for (int i=1;i<=temp.size;i++) {
        node->getKeys()->insert(temp.getPointer(i));
    }
}

void BinaryTree::insert(Key* k){
    BinaryTreeNode* temp = new BinaryTreeNode();
    temp = root;
    temp = getLeaf(temp, k->getKey());
    temp->getKeys()->insert(k);
    sort(temp);
    if(temp->getKeys()->size > temp->getT()-1){
        //split
    }
}

BinaryTreeNode* BinaryTree::getLeaf(BinaryTreeNode* nNode, string key){
    bool verify = false;
    if(!nNode->isLeaf()){
        for(int i =1; nNode->getKeys()->size;i++){
            if(key < nNode->getKeyAt(i)->getKey() && !verify){
                nNode = nNode->getChildrenAt(i);
                verify=true;
            }
        }
        if(!verify){
            nNode= nNode->getChildrenAt(nNode->getChildren()->size);
        }
        nNode = getLeaf(nNode, key);
    }
    return nNode;
}

/*

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
>>>>>>> 247022649874dce1a955106aea5c889f7769d2ab
*/
