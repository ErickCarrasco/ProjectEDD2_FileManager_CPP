#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(){
	
}

BinaryTreeNode::BinaryTreeNode(int nT){
    T=nT;//Orden Arbol
    t=(nT-1)/2;//Minimum keys per node
    //Create Lists
    keys = new List<Key*>;
    children = new List<BinaryTreeNode*>;
}

//Getters
List<Key*>* BinaryTreeNode::getKeys(){
    return keys;
}

Key* BinaryTreeNode::getKeyAt(int index){
    return keys->get(index);
}

BinaryTreeNode* BinaryTreeNode::getParent(){
    return parent;
}

int BinaryTreeNode::getT(){
    return T;
}

int BinaryTreeNode::getMinimum(){
    return t;
}

List<BinaryTreeNode*>* BinaryTreeNode::getChildren(){
    return children;
}

BinaryTreeNode* BinaryTreeNode::getChildrenAt(int index){
    return children->get(index);
}

//Setter
void BinaryTreeNode::setParent(BinaryTreeNode* parentNode){
    parent = parentNode;
}

//Others
bool BinaryTreeNode::isLeaf(){
    return children->size==0;
}

string BinaryTreeNode::toString(){
    string temporary;
    temporary="";
    for (int i = 1; i <= keys->size; i++) {
        temporary+=(keys->get(i)->getKey()) + ";" + to_string(keys->get(i)->getIndex());
        if(i<keys->size){
            temporary+="|";
        }

    }

    return temporary;

}

void BinaryTreeNode::addChild(BinaryTreeNode* child){
    child->parent = this;
    children->insert(child);
}

void BinaryTreeNode::removeLastChild(){
    children->remove(children->size);
}

BinaryTreeNode::~BinaryTreeNode(){

}
