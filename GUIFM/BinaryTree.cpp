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
        split(temp);
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

void BinaryTree::split(BinaryTreeNode* Node){
    BinaryTreeNode* Top = Node->getParent();
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

    //Verify if Top exists
    if(Top==NULL){
        Top = new BinaryTreeNode(T);//Creates a new Node
        Top->getKeys()->insert(Node->getKeyAt(halfNum));//Inserts the key at the middle of the splitting node into the Top
        sort(Top);//Sorts top to keep an order
        Top->addChild(leftNode);//Inserts child
        Top->addChild(rightNode);//Inserts child
        root = Top;//Top becomes root, root now has the elements of Top
    }else{//If Top exists
        int index = Top->getChildren()->IndexOf(Node);
        Top->getKeys()->insert(Node->getKeyAt(halfNum));//Inserts the key at the Top Node
        sort(Top);//Orders the Top Node
        leftNode->setParent(Top);//The left node has the Top as parent
        Top->getChildren()->replace(index, leftNode);//Replacing the old node with the new one
        Top->addChild(rightNode);//Adds the new Node right as a child
        for (int i = Top->getChildren()->size;  i>index+1;i--) {
            Top->getChildren()->swap(i, i-1);
        }
    }
    if(Top->getKeys()->size > T-1){//In case that the Top has full keys
        split(Top);
    }

}

void BinaryTree::remove(string key){
    BinaryTreeNode* temp = new BinaryTreeNode(T);
    temp = root;
    temp = findNode(temp, key);
    for(int i=1; i<= temp->getKeys()->size;i++){
        if(key == temp->getKeyAt(i)->getKey()){
            temp->getKeys()->remove(i);
        }
    }
    if(temp->getKeys()->size<t){
        //merge(temp);
    }
}

BinaryTreeNode* BinaryTree::findNode(BinaryTreeNode* Node, string key){
    bool verify = false;
    if(!Node->isLeaf()){
        for (int i = 1;i<= Node->getKeys()->size; i++) {
            if(key == Node->getKeyAt(i)->getKey()){
                return Node;
            }else if (key < Node->getKeyAt(i)->getKey() && !verify) {
                Node = Node->getChildrenAt(i);
                verify = true;
            }
        }
        if(!verify){
            Node = Node->getChildrenAt(Node->getChildren()->size);
        }
        return findNode(Node, key);
    }else{
        for (int i = 1;i<=Node->getKeys()->size;i++) {
            if(key == Node->getKeyAt(i)->getKey()){
                return Node;
            }
        }
    }
    return NULL;
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
