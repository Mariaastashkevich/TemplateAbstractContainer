//
//  abstractcontainer.cpp
//  Abstract_Container
//
//  Created by MacBook Air M1 on 19.03.23.
//

#include "listqueue.h"
#include "liststack.h"
#include "arrayqueue.h"
#include "unlimitedstack.h"
#include "limitedstack.h"
template <typename T>
Abstract_Container::Abstract_Queue::ListQueue::ListQueue():
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
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
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
