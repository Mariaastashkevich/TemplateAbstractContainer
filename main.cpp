//
//  main.cpp
//  Abstract_Container
//
//  Created by MacBook Air M1 on 20.02.23.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "listqueue.h"
#include "liststack.h"
#include "arrayqueue.h"
#include "unlimitedstack.h"
#include "limitedstack.h"
#include "abstractct.h"
using namespace std;
int main(int argc, const char * argv[]) {
    RealUnLimitedStack<int> unlimstack; // stack
    LimitedStack<int> limstack; // stack
    ListStack<int> liststack; // stack
    ListQueue<int> listqueue;// queue
    ArrayQueue<int> arr_queue; // queue
    for(int i=1; i<8; i++){
    liststack.AddBack(i);
    }
    liststack.Show();
    liststack.Pop();
    liststack.Pop();
    liststack.Show();
    cout << "Top of stack: " << liststack.Top() << endl;
    return 0;
}
