//
//  main.cpp
//  Genric function template
//
//  Created by Amartya Vibhu on 18/08/22.
//

#include<iostream>
#include<string>



template<typename T>
T min(T a, T b){
    return(a<b)?a:b;
}

template<typename T1, typename T2>
void func(T1 a, T2 b){
    std::cout<<a<<" "<<b<<std::endl;
}

struct Person{
    std::string name;
    int age;
    bool operator<(const Person &rhs)const{
        return this->age<rhs.age;
    }
};

template<typename T3>
void my_swap(T3 &c,T3 &d){
    T3 temp = c;
    c = d;
    d = temp;
    
}

int main(){
    
    int c{100};
    int d{200};
    std::cout<<c<<","<<d<<std::endl;
    my_swap(c, d);
    std::cout<<c<<","<<d<<std::endl;
    
    
    
    Person p1{"Curly",55};
    Person p2{"Moe",30};
    Person p3 = min(p1,p2);
    std::cout<<p3.name<<"is younger"<<std::endl;
    
    
    
    std::cout<<min<int>(2,3)<<std::endl;
    std::cout<<min(2,3)<<std::endl;
    std::cout<<min('A','B')<<std::endl;
    std::cout<<min(12.5,9.2)<<std::endl;
    std::cout<<min(5+2*2,7+40)<<std::endl;
    
    return 0;
    
}
