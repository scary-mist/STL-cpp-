//
//  main.cpp
//  Queue STL
//
//  Created by Amartya Vibhu on 30/08/22.
//

#include <iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;

template <typename T>
void display(queue<T> q){
    cout<<"[";
    while(!q.empty()){
        T elem = q.front();
        q.pop();
        cout<<elem<<" ";
    }
    cout<<"]"<<endl;
}


int main() {
    queue<int>q;
    for(int  i: {1,2,3,4,5})
        q.push(i);
    display(q);
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    
    q.push(100);
    display(q);
    
    q.pop();
    q.pop();
    display(q);
    
    cout<<"Size: "<<q.size()<<endl;
    
    while(!q.empty())
        q.pop();
    display(q);
    
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
    return 0;
}
