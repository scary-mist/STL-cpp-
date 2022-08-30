//
//  main.cpp
//  LISTS STL
//
//  Created by Amartya Vibhu on 25/08/22.
//

#include <iostream>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

class Person{
    friend ostream &operator<<(ostream &os, const Person &p);
    string name;
    int age;
public:
    Person(): name{"Unknown"},age{0}{}
    Person(string name, int age):name{name},age{age}{}
    bool operator<(const Person &rhs) const{
        return this ->age<rhs.age;
    }
    bool operator == (const Person &rhs) const{
        return (this->name == rhs.name && this->age == rhs.age );
    }
};
ostream &operator<<(ostream &os, const Person &p){
    os<<p.name<<":"<<p.age;
    return os;
}
template<typename T>
void display(const list<T> &l){
    cout<<"[";
    for(const auto &elem : l){
        cout<<elem<<" ";
    }
    cout<<"]";
}

void test1(){
    cout<<"Test1================================"<<endl;
    list<int>l1{1,2,3,4,5};
    display(l1);
    list<string>l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

}
void test2(){
    cout<<"Test2================================"<<endl;
    list<int>l1{1,2,3,4,5,6,7,8,9,10};
    display(l1);
    cout<<"Size: "<<l1.size()<<endl;
    cout<<"Front: "<<l1.front()<<endl;
    cout<<"Back: "<<l1.back()<<endl;
    l1.clear();
    cout<<"Size"<<l1.size()<<endl;
    
}
void test3(){
    cout<<"Test3======================================="<<endl;
    list<int>l1{1,2,3,4,5,6,7,8,9,10};
    display(l1);
    cout<<endl;
    l1.resize(5);
    display(l1);
    cout<<endl;
    l1.resize(10);
    display(l1);
    cout<<endl;
    
    list<Person>persons;
    persons.resize(5);
    display(persons);
    cout<<endl;
}
void test4(){
    cout<<"Test4================================"<<endl;
    list<int>l2{1,2,3,4,5,6,7,8,9,10};
    display(l2);
    cout<<endl;
    auto it = find(l2.begin(),l2.end(),5);
    if(it != l2.end()){
        l2.insert(it,100);
    }
    display(l2);
    cout<<endl;
    list<int>l3{1000,2000,3000};
    l2.insert(it,l3.begin(),l3.end());
    display(l2);
    cout<<endl;
    advance(it,-4); //  points to the 100
    cout<<*it<<endl;
    l2.erase(it);   // removes 100
    display(l2);
    cout<<endl;
}
void test5(){
    cout<<"Test5===================================="<<endl;
    list<Person>stooges{
        {"Larry",18},
        {"Moe",25},
        {"Curly",17}
    };
    display(stooges);
    cout<<endl;
    string name;
    int age{};
    cout<<"Enter the name of next stooge: ";
    getline(cin,name);
    cout<<"Enter their age: ";
    cin>>age;
    stooges.emplace_back(name,age);
    display(stooges);
    cout<<endl;
    
    auto it = find(stooges.begin(),stooges.end(),Person{"Moe",25});
    if(it != stooges.end())
        stooges.emplace(it,"Frank",18);
    display(stooges);
    cout<<endl;
}
void test6(){
    cout<<"Test6========================================"<<endl;
    list<Person>stooges{
        {"Larry",18},
        {"Moe",25},
        {"Curly",17}
    };
    display(stooges);
    cout<<endl;
    stooges.sort();
    display(stooges);
    
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
