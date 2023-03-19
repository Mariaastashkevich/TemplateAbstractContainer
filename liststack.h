//
//  liststack.h
//  Abstract_Container
//
//  Created by MacBook Air M1 on 19.03.23.
//

#ifndef liststack_h
#define liststack_h
//template <typename T>
//class Abstract_Container{
//public:
//    virtual int Size() = 0;
//    virtual bool IsEmpty() =0;
//};
template <typename T>
class Abstract_Stack : public Abstract_Container<T>{
public:
    virtual void Push(T value) = 0;
    virtual void Pop() = 0;
    virtual T Top() = 0;
};
//template <typename T>
//struct Node{
//    T data;
//    Node<T>* next;
//};
template <typename T>
class ListStack : public Abstract_Stack<T>{
public:
    ListStack():
    head(nullptr), size_(0){
    }
    int Size(){
    return size_;
    }
    bool IsEmpty(){
        if(size_==0) return true;
        return false;
    }
    void Push(T value){
        if(IsEmpty()){
        Node<T>* new_head=new Node<T>{value,NULL};
        head = new_head;
        }
        else{
        Node<T>* new_head= new Node<T>{value,head};
        head = new_head;
        }
        size_++;
    }
    void AddBack(T value){
        if(IsEmpty()){
        Node<T>* new_head=new Node<T>{value,NULL};
        head = new_head;
        }
        else{
        //Node* new_tail=new Node{value,};
            Node<T>* curr = head;
            while(curr->next!=NULL){
            curr=curr->next;
            }
        Node<T>* new_tail=new Node<T>{value,NULL};
            curr->next = new_tail;
        }
        size_++;
    }
    void Pop(){
    if(IsEmpty()) return;
    Node<T>* old_head =head;
    head=head->next;
    delete old_head;
    old_head=nullptr;
    size_--;
    }
    void PopBack(){
        if(IsEmpty()) return;
        Node<T>* curr = head;
        while(curr->next->next!=NULL){
        curr=curr->next;
        }
        Node<T>* old_tail = curr->next;
        delete old_tail;
        curr->next=NULL;
    }
    int IndexOfNode(T value){
        Node<T>* curr=head; int count =0;
        while(curr!=NULL){
        if(curr->data==value) return count;
        curr=curr->next;
        count++;
        }
        return -1;
    }
    T Top(){
    return head->data;
    }
    void Show(){
        Node<T>* curr = head;
        while(curr!=NULL){
        std::cout << curr->data << " ";
        curr=curr->next;
        }
        std::cout << std::endl;
    }
private:
    Node<T>* head;
    int size_;
};

#endif /* liststack_h */
