//
//  unlimitedstack.h
//  Abstract_Container
//
//  Created by MacBook Air M1 on 19.03.23.
//

#ifndef unlimitedstack_h
#define unlimitedstack_h
//class Abstract_Container{
//public:
//    virtual int Size() = 0;
//    virtual bool IsEmpty() =0;
//};
//template <typename T>
//class Abstract_Stack : public Abstract_Container<T>{
//public:
//    virtual void Push(T value) = 0;
//    virtual void Pop() = 0;
//    virtual T Top() = 0;
//};
template <typename T>
class RealUnLimitedStack : public Abstract_Stack<T>{
public:
    int Size(){
    return size_;
    }
    bool IsEmpty(){
        if(size_==0) return true;
        return false;
    }
    RealUnLimitedStack(int size){
        size_ = size;
        unlimstack = new T[size_];
        for(int i=0; i<size_; i++){
        unlimstack[i] =0;
        }
    }
    RealUnLimitedStack():
        size_(0),unlimstack(nullptr) {

        }
        RealUnLimitedStack(const RealUnLimitedStack& other){
            size_ = other.size_;
            delete unlimstack;
            unlimstack = new T[size_];
            for(int i=0; i<size_; i++){
            unlimstack[i] = other.unlimstack[i];
            }
    }
    RealUnLimitedStack(RealUnLimitedStack&& other){
        size_=other.size_;
        unlimstack=other.unlimstack;
        other.unlimstack=NULL;
        other.size_=0;
    }
    RealUnLimitedStack& operator=(RealUnLimitedStack&& other){
        if(this==&other) return *this;
        delete unlimstack;
        size_=other.size_;
        unlimstack=other.unlimstack;
        other.unlimstack=NULL;
        other.size_=0;
        return *this;
    }
    RealUnLimitedStack& operator=(const RealUnLimitedStack& other){
        if(this == &other) return *this;
        size_ = other.size_;
        unlimstack = new T[size_];
        for(int i=0; i<size_; i++){
        unlimstack[i] = other.unlimstack[i];
        }
        return *this;
    }
    void Push(T value){
    T* new_stack = new T[size_+1];
        for(int i=0; i<size_; i++){
        new_stack[i] = unlimstack[i];
        }
        delete [] unlimstack;
        unlimstack = new_stack;
        unlimstack[size_] = value;
        size_++;
    }
    void Pop(){
    if(size_==0) return;
    T* new_stack = new T[size_-1];
        for(int i=0; i<size_-1; i++){
        new_stack[i] = unlimstack[i+1];
        }
        delete [] unlimstack;
        unlimstack = new_stack;
        size_--;
    }
    T Top(){
    if(IsEmpty()) return -1;
    return unlimstack[0];
    }
    void Show(){
        for(int i=0; i<size_; i++){
        std::cout << unlimstack[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    int size_;
    T* unlimstack;
    
};
#endif /* unlimitedstack_h */
