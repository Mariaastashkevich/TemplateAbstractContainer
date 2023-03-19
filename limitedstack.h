//
//  limitedstack.h
//  Abstract_Container
//
//  Created by MacBook Air M1 on 19.03.23.
//

#ifndef limitedstack_h
#define limitedstack_h
//template <typename T>
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
class LimitedStack : public Abstract_Stack<T>{
public:
    LimitedStack<T>():
    size_(0), limstack(nullptr){
    }
    LimitedStack(int size){
        if(size>limit) throw std::runtime_error("Entered size is greater that maximal possible:(");
        else {size_ = size;
        limstack = new T[size_];
        for(int i=0; i<size_; i++){
            limstack[i] = 0;
        }
      }
    }
    LimitedStack(const LimitedStack& other){
        size_ = other.size_;
        limstack = new T[size_];
        for(int i=0; i<size_; i++){
        limstack[i] = other.limstack[i];
        }
    }
    LimitedStack(LimitedStack&& other){
        size_ = other.size_;
        limstack=other.limstack;
        other.limstack=NULL;
        other.size_=0;
    }
    int Size(){
        return size_;
    }
    LimitedStack& operator=(LimitedStack&& other){
        if(this==&other) return *this;
        delete limstack;
        size_=other.size_;
        limstack=other.limstack;
        other.limstack=NULL;
        other.size_=0;
        return *this;
    }
    LimitedStack& operator=(const LimitedStack& other){
        if(this == &other) return *this;
        size_ = other.size_;
        delete [] limstack;
        limstack = new int[other.size_];
        for(int i=0; i<size_; i++){
        limstack[i] = other.limstack[i];
        }
        return *this;
    }
    void Push(T value){
    if(size_==limit) throw std::runtime_error("Size cannot be increased!");
    else{
    T* new_stack = new T[size_+1];
        for(int i=0; i<size_; i++){
        new_stack[i] = limstack[i];
        }
        delete [] limstack;
        limstack = new_stack;
        limstack[size_] = value;
        size_++;
    }
    }
    bool IsEmpty(){
    if(size_==0) return true;
    return false;
    }
    void Pop(){
    if(IsEmpty()) return;
    else{
    T* new_stack = new T[size_-1];
        for(int i=0; i<size_-1; i++){
        new_stack[i] = limstack[i+1];
        }
        delete [] limstack;
        limstack = new_stack;
        size_--;
    }
    }
    T Top(){
    if(IsEmpty()) return -1;
    else return limstack[0];
    }
    void Show(){
        for(int i=0; i<size_; i++){
        std::cout << limstack[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    int size_;
    T* limstack;
    int limit = 1000;
};
#endif /* limitedstack_h */
