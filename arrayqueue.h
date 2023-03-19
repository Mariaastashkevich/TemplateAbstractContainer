//
//  arrayqueue.h
//  Abstract_Container
//
//  Created by MacBook Air M1 on 19.03.23.
//

#ifndef arrayqueue_h
#define arrayqueue_h
//template <typename T>
//class Abstract_Container{
//public:
//    virtual int Size() = 0;
//    virtual bool IsEmpty() =0;
//};
template <typename T>
class ArrayQueue : public Abstract_Queue<T>{
public:
    ArrayQueue():
    size_(0),queue(NULL){
    }
    ArrayQueue(int size){
        size_ = size;
        queue = new T[size_];
        for(int i=0; i<size_; i++){
            queue[i]= 0;
        }
    }
    ArrayQueue(const ArrayQueue& other){
        size_ = other.size_;
        queue = new T[size_];
        for(int i=0; i<size_; i++){
        queue[i] = other.queue[i];
        }
    }
    ArrayQueue(ArrayQueue&& othr){
        size_ = othr.size_;
        queue = othr.queue;
        othr.queue=NULL;
        othr.size_=0;
    }
    ArrayQueue& operator=(ArrayQueue&& other){
        if(this==&other) return *this;
        delete queue;
        size_=other.size_;
        queue=other.queue;
        other.queue=NULL;
        other.size_=0;
        return *this;
    }
    ArrayQueue& operator=(const ArrayQueue& other){
        if(&other == this) return *this;
        size_ = other.size_;
        delete queue;
        queue = new T[size_];
        for(int i=0; i<size_; i++){
        queue[i] = other.queue[i];
        }
        return *this;
    }
    int Size(){
        return size_;
    }
    bool IsEmpty(){
        if(size_==0) return true;
        return false;
    }
    void EnQueue(T value){
        T* new_arr = new T[size_+1];
        for(int i=0; i<size_; i++){
        new_arr[i] = queue[i];
        }
        delete queue;
        queue = new_arr;
        queue[size_] = value;
    }
    T DeQueue(){
        T* new_arr = new T[size_-1];
        for(int i=0; i<size_-1; i++){
        new_arr[i] = queue[i];
        }
        T res = queue[size_-1];
        delete queue;
        queue = new_arr;
        return res;
    }
    T Peek(){
    return queue[size_-1];
    }
    int Count(){
        return size_;
    }
    T Top(){
    return queue[0];
    }
private:
    int size_;
    T* queue;
};

#endif /* arrayqueue_h */
