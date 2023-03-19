//
//  listqueue.h
//  Abstract_Container
//
//  Created by MacBook Air M1 on 19.03.23.
//

#ifndef listqueue_h
#define listqueue_h
template <typename T>
struct Node{
    T data;
    Node<T>* next;
};
template <typename T>
class Abstract_Container{
public:
    virtual int Size() = 0;
    virtual bool IsEmpty() =0;
};
template <typename T>
class Abstract_Queue : public Abstract_Container<T>{
    virtual void EnQueue(T value) = 0;
    virtual T DeQueue() = 0;
    virtual T Peek() = 0;
    virtual int Count() =0;
    
};
template <typename T>
class ListQueue : public Abstract_Queue<T>{
public:
    ListQueue():
    size_(0),head(nullptr){
    }
    void EnQueue(T value){ // AddFront
        if(size_==0) head = new Node<T>{value,NULL};
        else{
        Node<T>* new_head = new Node<T>{value,head};
        head = new_head;
        size_++;
        }
    }
    T DeQueue(){
        Node<T>* curr = head;
        while(curr->next->next!=NULL){
        curr=curr->next;
        }
        Node<T>* old_tail = curr->next;
        int res = old_tail->data;
        delete old_tail;
        curr->next = NULL;
        return res;
    }
    void Show(){
        Node<T>* curr = head;
        while(curr!=NULL){
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    T Peek(){
        Node<T>* curr = head;
        while(curr->next!=nullptr){
        curr=curr->next;
        }
        return curr->data;
    }
    int Count(){
    return size_;
    }
    bool IsEmpty(){
        if(size_==0) return true;
        return false;
    }
    int Size(){
        return size_;
    }
private:
    int size_;
    Node<T>* head;
};
#endif /* listqueue_h */
