//
//  main.cpp
//  Map STL
//
//  Created by Amartya Vibhu on 27/08/22.
//

#include <iostream>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

void display(const std::map<std::string, std::set<int>> &m){
    cout<<"[";
    for(const auto &elem : m){
        cout<<elem.first<<":[";
        for(const auto &set_elem: elem.second){
            cout<<set_elem<<" ";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
}
template<typename T1, typename T2>
void display(const map<T1, T2> &l){
    cout<<"[";
    for(const auto &elem: l){
        cout<<elem.first<<":"<<elem.second<<" ";
    }
    cout<<"]"<<endl;
}

void test1(){
    cout<<"Test1===================================="<<endl;
    map<string, int>m{
        {"Larry",3},
        {"Moe",1},
        {"Curly",2}
    };
    display(m);
    
    m.insert(pair<string,int>("Anna",10));
    display(m);
    
    m.insert(make_pair("Joe",5));
    display(m);
    
    m["Frank"]=10;
    display(m);
    
    m["Frank"] += 18;
    display(m);
    
    m.erase("Frank");
    display(m);
    
    cout<<"Count for Joe is: "<<m.count("Joe")<<endl;
    cout<<"Count for Frank is: "<<m.count("Frank")<<endl;
    
    auto it = m.find("Larry");
    if(it != m.end()){
        cout<<"Found: "<<it->first<<" , "<<it->second<<endl;
    }
    m.clear();
    display(m);
}

void test2(){
    cout<<"Test2======================================"<<endl;
    map<string,set<int>>grades{
        {"Larry",{100,90}},
        {"Moe",{94}},
        {"Curly",{80,90,100}}
    };
    display(grades);
    grades["Larry"].insert(95);
    display(grades);
    
    auto it = grades.find("Moe");
    if(it != grades.end()){
        it->second.insert(1000);
    }
    display(grades);
}
int main() {
    test1();
    test2();
    return 0;
}
