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

};
#endif // LINKEDLIST_H
