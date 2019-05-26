#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Double linked-list
template<class T>
class NodeList{
protected:
    T data;
    NodeList<T>* prev;
    NodeList<T>* next;

public:
    NodeList<T>(T nData){
        data = nData;
        prev = 0;
        next = 0;
    }

    //Getters NodeList
    T getData(){
        return data;
    }

    NodeList<T>* getPrevious(){
        return prev;
    }

    NodeList<T>* getNext(){
        return next;
    }

    //Setters Nodelist
    void setData(T nData){
        data = nData;
    }

    void setPrevious(NodeList<T>* nPrevious){
        prev = nPrevious;
    }

    void setNext(NodeList<T>* nNext){
        next = nNext;
    }

    ~NodeList(){
        if(next != 0){
            delete next;
        }
        prev = 0;
    }

};

template <class T>
class List{
protected:
    NodeList<T>* tail;
    NodeList<T>* head;

public:
    int size;
    int cap;

    //Constructor

    List<T>(){
        tail = 0;
        head = 0;
        size = 0;
        cap = -1;
    }

    List<T>(int nCap){
        tail = 0;
        head = 0;
        size = 0;
        cap = nCap;
    }

    //Setter Capacity
    void setCap(int nCapacity){
        cap = nCapacity;
    }

    //FUNCTIONS
    //

    //Insert Node
    bool insert(T data){
        if(size >=cap && cap !=-1){
            return false;
        }
        else{
            NodeList<T>* temp = new NodeList<T>(data);

            //Validate head and tail
            if (head == 0) {
                head = temp;
                tail = temp;
            }else{
                temp->setPrevious(tail);
                tail->setNext(temp);
                tail = temp;
            }

            size++;
            return true;
        }

    }

    //GET Node
    T get(int index){
        NodeList<T>* currentNode = head;
        for (int i = 2; i<= index;i++) {
            if(currentNode != 0){
                currentNode = currentNode->getNext();
            }
        }
        return currentNode->getData();
    }

    //REMOVE Node
    bool remove(int index){
        if (index>size) {
            return false;
        }else{
            NodeList<T>* currentNode = head;
            for (int i =2;i<=index;i++) {
                currentNode = currentNode->getNext();
            }

            NodeList<T>* previous = currentNode->getPrevious();
            NodeList<T>* next = currentNode->getNext();

            if(previous != 0 ){
                previous->setNext(next);
            }

            if (next != 0) {
                next->setPrevious(previous);

                if(previous == 0){
                    head = next;
                }
            }else {
                if(size==2){
                    head = tail;
                }
            }

            currentNode->setNext(0);
            currentNode->setPrevious(0);
            size--;

            if(size == 2){
                head ->setNext(tail);
                tail ->setPrevious(head);
            }
            return true;
        }
    }

    //REPLACE NODE Data
    bool replace(int index, T nData){
        NodeList<T>* currentNodeList = head;
        for (int i = 2;i <= index;i++) {
            if (currentNodeList != 0) {
                currentNodeList = currentNodeList->getNext();
            }
        }

        if (currentNodeList != 0) {
            currentNodeList->setData(nData);
            return true;
        }
        return false;
    }

    //ClearN
    void clear(){
      if (head != 0) {
        delete head;
      }

      head = 0;
      tail = 0;
      size = 0;
    }

    //Verify ifFull
    bool isFull(){
      if (size >= cap && cap != -1) {
        return true;
      }

      return false;
    }

    //Contains target
    bool contains(T target){
      for (int i = 1; i <= size; i++) {
        if (target == get(i)) {
          return true;
        }
      }

      return false;
    }


    //Verify ifEmpty
    bool isEmpty(){
      if (size == 0) {
        return true;
      }

      return false;
    }

    //GET NODE
    NodeList<T>* getNodeList(int index){
        if(index <= 1){
            return head;
        }else{
            NodeList<T>* currentNodeList = head;
            for (int i = 2;i <= index; i++) {
                currentNodeList = currentNodeList->getNext();
            }
            return currentNodeList;
        }
    }

    //FIND NODE
    NodeList<T>* findNodeList(T maindata){
        NodeList<T>* currentNodeList = head;

        while (currentNodeList != 0) {
            if (currentNodeList->getData()==maindata) {
                return currentNodeList;
            }else {
                currentNodeList = currentNodeList->getNext();
            }
        }

        return 0;
    }

    //NODE SWAP
    void swap(int index1, int index2){
        if(index1 <= size && index2 <= size && index1 > 0 && index2>0){
            NodeList<T>* n1 = getNodeList(index1);
            NodeList<T>* n2 = getNodeList(index2);

            T temporary = n1->getData();
            n1->setData(n2->getData());
            n2->setData(temporary);
        }
    }

    //SORT
    void sort(){
        if(size<2){
            return;
        }

        for (int i = 1;i <= size; i++) {
            for (int j = 1; j < size; j++) {
                if (get(j) > get(j+1)) {
                    swap(j, j+1);
                }

            }
        }
    }

    //DEQUEUE
    T dequeue(){
        T temp = head->getData();
        remove(1);
        return temp;
    }

    //Destructor
    ~List<T>(){

    }

};
#endif // LINKEDLIST_H
