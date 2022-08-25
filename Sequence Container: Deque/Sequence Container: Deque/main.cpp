//
//  main.cpp
//  Sequence Container: Deque
//
//  Created by Amartya Vibhu on 24/08/22.
//

#include <iostream>
#include<deque>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
void display(const deque<T> &d){
    cout<<"[";
    for(const auto &elem: d)
        cout<<elem<<" ";
    cout<<"]"<<endl;
}
void test1(){
    cout<<"Test1================================="<<endl;
    deque<int>d{1,2,3,4,5};
    display(d);
    d = {2,4,5,6};
    display(d);
    deque<int>d1(10,100);
    display(d1);
    d.at(0)=100;
    d[1]=200;
    display(d);
}
void test2(){
    cout<<"Test2================================="<<endl;
    deque<int>d{0,0,0};
    display(d);
    d.push_back(10);
    d.push_back(20);
    display(d);
    
    d.push_front(100);
    d.push_front(200);
    display(d);
    
    cout<<"Front: "<<d.front()<<endl;
    cout<<"Back: "<<d.back()<<endl;
    cout<<"Size: "<<d.size()<<endl;
    
    d.pop_back();
    d.pop_front();
    display(d);
    
}
void test3(){
    cout<<"Test3================================="<<endl;
//    Insert all even nos. to back of a deque and odd to the front.
    vector<int>vec{1,2,3,4,5,6,7,8,9,10};
    deque<int>d;
    for(const auto &elem: vec){
        if(elem % 2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }
    display(d);
    
}
void test5(){
    cout<<"Test5================================="<<endl;

    vector<int>vec{1,2,3,4,5,6,7,8,9,10};
    deque<int>d;
    
    copy(vec.begin(),vec.end(),front_inserter(d));
    display(d);
    d.clear();
    copy(vec.begin(),vec.end(),back_inserter(d));
    display(d);
    
}


int main() {
    test1();
    test2();
    test3();
    test5();
    return 0;
}
