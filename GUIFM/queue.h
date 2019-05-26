#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class QueueNode{

private:
    T data;
    QueueNode<T>* next;
    QueueNode<T>* prev;

public:
    QueueNode(T nData){
        data = nData;
        next = 0;
        prev = 0;

    }

    T getData(){
        return data;
    }

    void setData(T nData){
        data = nData;
    }

    QueueNode<T>* getNext(){
        return next;
    }

    void setNext(QueueNode<T>* nNextQueueNode){
        next = nNextQueueNode;
    }

    QueueNode<T>* getPrevious(){
        return prev;
    }

    void setPrevious(QueueNode<T>* nPrevQueueNode){
        prev = nPrevQueueNode;
    }


};



#endif // QUEUE_H
