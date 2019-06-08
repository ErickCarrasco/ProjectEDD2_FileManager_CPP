#include "BinaryTree.h"
#include <string>
#include <vector>
#include <iostream>

BinaryTree::BinaryTree() {
}

BinaryTree::BinaryTree(int pT) {
  root = new BinaryTreeNode(pT);
  T=pT;
  t=(pT-1)/2;
}

BinaryTreeNode* BinaryTree::getRoot(){
  return root;
}

void BinaryTree::sort(BinaryTreeNode* node){
  List<Key> temp;
  for (int i = 1; i <= node->getKeys()->size; i++) {
    temp.insert(*node->getKeyAt(i));
  }
  temp.sort();
  node->getKeys()->clear();

  for (int i = 1; i <= temp.size; i++) {
    node->getKeys()->insert(temp.getPointer(i));
  }
}

void BinaryTree::insert(Key* key){
  BinaryTreeNode* temp = new BinaryTreeNode(T);
  temp = root;
  temp = getLeaf(temp, key->getKey());
  temp->getKeys()->insert(key);
  sort(temp);
  if (temp->getKeys()->size > temp->getT()-1) {
    split(temp);
  }

}

void BinaryTree::split(BinaryTreeNode* node){
  BinaryTreeNode* top = node->getParent();
  BinaryTreeNode* left = new BinaryTreeNode(T);
  BinaryTreeNode* right = new BinaryTreeNode(T);
  int half = 1 + ((node->getKeys()->size-1) / 2);
  //int key = node->getKeysAt(node->getKeys()->size);

  for (int i = 1; i <= node->getKeys()->size; i++) {
    if (i<half) {
      left->getKeys()->insert(node->getKeyAt(i));
    }else if (i>half) {
      right->getKeys()->insert(node->getKeyAt(i));
    }
  }

  for (int i = 1; i <= node->getChildren()->size; i++) {
    if (i<=half) {
      left->addChild(node->getChildrenAt(i));
    }else {
      right->addChild(node->getChildrenAt(i));
    }
  }

  if (top == NULL) {
    top = new BinaryTreeNode(T);
    top->getKeys()->insert(node->getKeyAt(half));
    sort(top);
    top->addChild(left);
    top->addChild(right);
    root = top;
  }else{
    int index = top->getChildren()->IndexOf(node);
    top->getKeys()->insert(node->getKeyAt(half));
    sort(top);
    left->setParent(top);
    top->getChildren()->replace(index, left);
    top->addChild(right);
    for (int i = top->getChildren()->size; i > index+1; i--) {
      top->getChildren()->swap(i, i-1);
    }
  }

  if (top->getKeys()->size > T-1) {
    split(top);
  }

}

void BinaryTree::remove(string key){
  BinaryTreeNode* temp = new BinaryTreeNode(T);
  temp = root;
  temp = findNode(temp, key);
  for (int i = 1; i <= temp->getKeys()->size; i++) {
    if (key==temp->getKeyAt(i)->getKey()) {
      temp->getKeys()->remove(i);
    }
  }
  if (temp->getKeys()->size < t) {
    merge(temp);
  }
}


void BinaryTree::merge(BinaryTreeNode* Node){
    BinaryTreeNode* NewNode = Node->getParent();
    BinaryTreeNode* leftNode = new BinaryTreeNode(T);//New Node
    BinaryTreeNode* rightNode = new BinaryTreeNode(T);//New Node
    int halfNum= ((Node->getKeys()->size-1)/2) + 1;//Gets the half number of the NodeKeys, allowing to get that key for later promotion
    //Inserting keys into the left and right nodes
    for(int i =1; i<=Node->getKeys()->size;i++){
        if(i<halfNum){//Inserts all the keys before the half key into the left node
            leftNode->getKeys()->insert(Node->getKeyAt(i));
        }else if (i>halfNum) {
            rightNode->getKeys()->insert(Node->getKeyAt(i));
        }
    }
    //Adding their respective children. Used mostly during deletes, and merges
    for (int i = 1;i<=Node->getChildren()->size;i++) {
        if(i<=halfNum){
            leftNode->addChild(Node->getChildrenAt(i));
        }else{
            rightNode->addChild(Node->getChildrenAt(i));
        }
    }
    for (int i=0;i<leftNode->getKeys()->size;i++) {
        NewNode->getKeys()->insert(leftNode->getKeyAt(i));
    }
    for (int i=0;i<rightNode->getKeys()->size;i++) {
        NewNode->getKeys()->insert(rightNode->getKeyAt(i));
    }
}


BinaryTreeNode* BinaryTree::getLeaf(BinaryTreeNode* node, string key){
  bool bandera = false;
  if (!node->isLeaf()) {

    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key < node->getKeyAt(i)->getKey() && !bandera) {
        node = node->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      node = node->getChildrenAt(node->getChildren()->size);
    }

    node = getLeaf(node, key);
  }
  return node;
}

int BinaryTree::findIndex(string key){
  return findIndex(root, key);
}

int BinaryTree::findIndex(BinaryTreeNode* node, string key){
  bool bandera = false;
  if (!node->isLeaf()) {

    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeyAt(i)->getKey()) {
        return node->getKeyAt(i)->getIndex();
      } else if (key < node->getKeyAt(i)->getKey() && !bandera) {
        node = node->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      node = node->getChildrenAt(node->getChildren()->size);
    }

    return findIndex(node, key);
  }else{
    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeyAt(i)->getKey()) {
        return node->getKeyAt(i)->getIndex();
      }
    }
  }
  return -1;
}

BinaryTreeNode* BinaryTree::findNode(BinaryTreeNode* node, string key){
  bool bandera = false;
  if (!node->isLeaf()) {

    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeyAt(i)->getKey()) {
        return node;
      } else if (key < node->getKeyAt(i)->getKey() && !bandera) {
        node = node->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      node = node->getChildrenAt(node->getChildren()->size);
    }

    return findNode(node, key);
  }else{
    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeyAt(i)->getKey()) {
        return node;
      }
    }
  }
  return NULL;
}

void BinaryTree::printPrev(){
  printString = "";
  printPrev(root);
}

void BinaryTree::printPrev(BinaryTreeNode* node){
  if (!node->isLeaf()) {
    printPrev(node->getChildrenAt(1));
    printString += node->toString();
    printString += '\n';

    for (int i = 2; i <= node->getChildren()->size; i++) {
      printPrev(node->getChildrenAt(i));
    }

  }else{
    printString += node->toString();
    printString += '\n';
  }
}

string BinaryTree::getString(){
  return printString;
}


