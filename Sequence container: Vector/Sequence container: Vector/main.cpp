//
//  main.cpp
//  Sequence container: Vector
//
//  Created by Amartya Vibhu on 24/08/22.
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Person{
    friend ostream &operator<<(ostream &os,const Person &p);
    string name;
    int age;
public:
    Person() = default;
    Person(string name, int age):name{name}, age{age} {}
    bool operator<(const Person &rhs)const{return this->age<rhs.age;}
    bool operator == (const Person &rhs)const{return (this->name == rhs.name && this->age == rhs.age);}
    
};

ostream &operator<<(ostream &os, const Person &p){
    os<<p.name<<":"<<p.age;
    return os;
}
void display2(const vector<int>&vec){
    cout<<"[";
    for_each(vec.begin(), vec.end(), [](int x){cout<<x<<" ";});
    cout<<"]"<<endl;
    
}
//Template function to display vectors
template<typename T>
void Display(const vector<T> &vec){
    cout<<"[";
    for(const auto &elem:vec)
        cout<<elem<<" ";
    cout<<"]"<<endl;
}

void test1(){
    cout<<"Test1============================================="<<endl;
    vector<int>vec{1,2,3,4,5};
    Display(vec);
    vec = {2,4,5,6};
    display2(vec);
    vector<int>vec1(10,100);
    display2(vec1);
}

void test2(){
    cout<<"Test2============================================="<<endl;
    vector<int>vec{1,2,3,4,5};
    display2(vec);
    cout<<"Size of vec is: "<<vec.size()<<endl;
    cout<<"Max size of vec is: "<<vec.max_size()<<endl;
    cout<<"Capacity of vec is: "<<vec.capacity()<<endl;
    
    vec.push_back(6);
    display2(vec);
    cout<<"Size of vec is: "<<vec.size()<<endl;
    cout<<"Max size of vec is: "<<vec.max_size()<<endl;
    cout<<"Capacity of vec is: "<<vec.capacity()<<endl;
//    Below method fits the vector.
    vec.shrink_to_fit();
    display2(vec);
    cout<<"Size of vec is: "<<vec.size()<<endl;
    cout<<"Max size of vec is: "<<vec.max_size()<<endl;
    cout<<"Capacity of vec is: "<<vec.capacity()<<endl;
//    Below method reserve the fix space for the vector
    vec.reserve(100);
    display2(vec);
    cout<<"Size of vec is: "<<vec.size()<<endl;
    cout<<"Max size of vec is: "<<vec.max_size()<<endl;
    cout<<"Capacity of vec is: "<<vec.capacity()<<endl;
}
void test4(){
    cout<<"Test4============================================="<<endl;
    vector<Person>stooges{};
    Person p1{"Larry",18};
    Display(stooges);
    stooges.push_back(p1);
    Display(stooges);
    
    stooges.push_back(Person{"Moe",25});
    Display(stooges);
    
    stooges.emplace_back("Curly",28);
    Display(stooges);
}
void test5(){
    cout<<"Test5============================================="<<endl;
    vector<Person>stooges{
        {"Larry",18},{"Moe",20},{"Curly",22}
    };
    Display(stooges);
    cout<<"Front element is: "<<stooges.front()<<endl;
    cout<<"Back element is: "<<stooges.back()<<endl;
    
    stooges.pop_back();
    Display(stooges);
}

void test6(){
    cout<<"Test6============================================"<<endl;
    vector<int>vec{1,2,3,4,5,6};
//    Remove all element
    vec.clear();
    display2(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display2(vec);
    vec.erase(vec.begin(),vec.begin() + 2);
    display2(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
//    erase all even numbers
    auto it = vec.begin();
    while(it != vec.end()){
        if(*it % 2 == 0)
            vec.erase(it);
        else
            it++;
    }
    display2(vec);
    
}
void test7(){
    cout<<"Test7============================================"<<endl;
    vector<int>vec1{1,2,3,4,5};
    vector<int>vec2{10,20,30,40,50};
    display2(vec1);
    display2(vec2);
    cout<<endl;
// Swap the two vectors
    vec1.swap(vec2);
    display2(vec1);
    display2(vec2);
}
void test8(){
    cout<<"Test8============================================"<<endl;
    vector<int>vec{1,21,45,11,2,6,9};
    sort(vec.begin(), vec.end());
    display2(vec);
    
}
void test9(){
//    std::back_inserter constructs a back insert iterator that insert new element
//    at the end of the container it is applied to and is very efficient.
//    There is also a front_inserter we can apply to Deque and lists.
//    copy one vec to another using iterator and front_inserter.
    
    cout<<"Test9============================================"<<endl;
    vector<int>vec1{1,2,3,4,5,6,7,8,9,10};
    vector<int>vec2{10,20};
    display2(vec1);
    display2(vec2);
    cout<<endl;
    copy(vec1.begin(), vec1.end(), back_inserter(vec2));
    display2(vec1);
    display2(vec2);
    
//    Copy_if the element is even
    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    display2(vec1);
    display2(vec2);
    cout<<endl;
    
    copy_if(vec1.begin(),vec1.end(), back_inserter(vec2),
            [](int x){return x % 2 == 0;});
    display2(vec1);
    display2(vec2);
}
void test10(){
    cout<<"Test10============================================"<<endl;
//    Transform over two ranges
    vector<int>vec1{1,2,3,4,5};
    vector<int>vec2{10,20,30,40,50};
    vector<int>vec3;
    
    transform(vec1.begin(), vec1.end(), vec2.begin(), back_inserter(vec3),
              [](int x, int y){return x * y;});
    
    display2(vec3);
}
void test11(){
    cout<<"Test11============================================"<<endl;
//    Insert vec2 into vec1 before 5
    vector<int>vec1{1,2,3,4,5,6,7,8,9,10};
    vector<int>vec2{100,200,300,400};
    auto it = find(vec1.begin(),vec1.end(),5);
    if(it != vec1.end()){
        cout<<"inserting..."<<endl;
        vec1.insert(it, vec2.begin(),vec2.end());
    }
    else{
        cout<<"Sorry, 5 not found."<<endl;
    }
    display2(vec1);
}


int main() {
    test1();
    test2();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    return 0;
}
