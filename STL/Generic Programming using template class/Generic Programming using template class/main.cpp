//
//  main.cpp
//  Generic Programming using template class
//
//  Created by Amartya Vibhu on 18/08/22.
//

#include<iostream>
#include<string>
#include <vector>

using namespace std;

template<typename T>
class Item{
private:
    string name;
    T value;

    
public:
    Item(string name,T value):name{name}, value{value}
    {}
    string get_name() const{return name;}
    T get_value() const{return value;}
};

template<typename T1, typename T2>
struct My_pair{
    T1 first;
    T2 second;
};

int main(){
    Item<int>item1{"Frank",100};
    cout<<item1.get_name()<<","<<item1.get_value()<<endl;
    Item<string>item2{"Frank","Professor"};
    cout<<item2.get_name()<<","<<item2.get_value()<<endl;
    
    Item<Item<string>>item3{"Frank",{"C++","Professor"}};
    cout<<item3.get_name()<<","<<item3.get_value().get_name()<<","<<item3.get_value().get_value()<<endl;
    
    cout<<"====================================================="<<endl;
    
    vector<Item<double>>vec{};
    vec.push_back(Item<double>("Larry",100.0));
    vec.push_back(Item<double>("Moe",200.0));
    vec.push_back(Item<double>("Frank",300.0));
    
    for(const auto &item: vec){
        cout<<item.get_name()<<","<<item.get_value()<<endl;
    }
    cout<<"====================================================="<<endl;
    
    My_pair<string, double>p1{"Frank", 100.0};
    My_pair<int, double>p2{100, 120.7};
    cout<<p1.first<<","<<p1.second<<endl;
    cout<<p2.first<<","<<p2.second<<endl;
    
    
    return 0;
    
};
