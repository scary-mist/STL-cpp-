//
//  main.cpp
//  Iterator stl
//
//  Created by Amartya Vibhu on 22/08/22.
//

#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<string>

using namespace std;

void display(const vector<int> &vec){
    cout<<"[";
    for(auto const &i:vec){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
}
void test1(){
    cout<<"=========================================="<<endl;
    vector<int>nums1{1,2,3,4};
    auto it = nums1.begin();
    cout<<*it<<endl;
    it++;
    cout<<*it<<endl;
    it+=2;
    cout<<*it<<endl;
    it -= 2;
    cout<<*it<<endl;
    it = nums1.end() - 1;
    cout<<*it<<endl;
    
}

void test2(){
    cout<<"=========================================="<<endl;
    vector<int>nums1{1,2,3,4,5};
    vector<int>::iterator it = nums1.begin();
    while(it!=nums1.end()){
        cout<<*it<<endl;
        it++;
    }
    while(it!=nums1.end()){
        *it=0;
        it++;
    }
    display(nums1);
}

void test3(){
//    using const_iterator
    cout<<"=========================================="<<endl;
    vector<int>nums1{1,2,3,4,5};
    vector<int>::const_iterator it1 = nums1.begin();
    
    while(it1 != nums1.end()){
        cout<<*it1<<endl;
        it1++;
    }
    

    
}

void test4(){
//    using reverse iterator
    vector<int>vec{1,2,3,4};
    auto it1 = vec.rbegin();
    while(it1!=vec.rend()){
        cout<<*it1<<endl;
        it1++;
        
    }
// using constant reverse iterator over a list
        list<string>name{"Larry","Moe","Curly"};
        auto it2 = name.crbegin();
        cout<<*it2<<endl;
        it2++;
        cout<<*it2<<endl;
        
        map<string,string>fav{
            {"Frank","C++"},
            {"Bill","java"},
            {"James","Kotlin"}
        };
        auto it3 = fav.begin();
        while(it3 != fav.end()){
            cout<<it3->first<<":"<<it3->second<<endl;
            it3++;
    }
}
void test5(){
//    iterate over a subset of a container
    vector<int>vec{1,2,3,4,5,6,7,8,9,10};
    auto start = vec.begin() + 2;
    auto end = vec.end() - 3;
    while(start != end){
        cout<<*start<<endl;
        start++;
    }
    
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
    return 0;
}
