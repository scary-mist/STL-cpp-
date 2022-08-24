//
//  main.cpp
//  Sequence Containers Array STL
//
//  Created by Amartya Vibhu on 23/08/22.
//

#include <iostream>
#include<algorithm>
#include<array>
#include<numeric>

using namespace std;
//Function to display the array
void display(const array<int, 5> &arr){
    cout<<"[";
    for(const auto &i:arr)
        cout<<i<<" ";
    cout<<"]"<<endl;
}
void test1(){
    cout<<"Test1-------------------------------------"<<endl;
    array<int, 5>arr1{1,2,3,4,5};
    array<int, 5>arr2;
    display(arr1);
    display(arr2);
    
    arr2 = {10,20,30,40,50};
    display(arr1);
    display(arr2);
    
    cout<<"Size of arr1 is: "<<arr1.size()<<endl;
    cout<<"Size of arr2 is: "<<arr2.size()<<endl;
    
    arr1.at(0)=1000;
    arr1[1] = 2000;
    
    display(arr1);
    
    cout<<"Front of arr2 is: "<<arr2.front()<<endl;
    cout<<"Back of arr2 is: "<<arr2.back()<<endl;
    
}
void test2(){
    cout<<"Test2-------------------------------------------"<<endl;
    array<int, 5>arr1{1,2,3,4,5};
    array<int,5>arr2{10,20,30,40,50};
    display(arr1);
    display(arr2);
    arr1.fill(0);
    display(arr1);
    display(arr2);
    arr1.swap(arr2);
    display(arr1);
    display(arr2);
}

void test3(){
    cout<<"Test3-------------------------------------------"<<endl;
    
    array<int, 5>arr1{1,2,3,4,5};
    int *ptr = arr1.data();
    cout<<ptr<<endl;
    *ptr = 1000;
    display(arr1);
}
void test4(){
    cout<<"Test4---------------------------------------------"<<endl;
    array<int,5>arr1{4,5,3,2,1};
    display(arr1);
    sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5(){
    cout<<"Test5---------------------------------------------"<<endl;
    array<int,5>arr1{4,5,3,2,1};
    
    array<int,5>::iterator min_num = min_element(arr1.begin(), arr1.end());
    auto max_num = max_element(arr1.begin(), arr1.end());
    
    cout<<"Minimum number is: "<<*min_num<<" And Maximum number is: "<<*max_num<<endl;
}

void test6(){
    cout<<"Test5----------------------------------------------"<<endl;
    
    array<int,5>arr1{1,5,3,3,5};
    auto adjecent = adjacent_find(arr1.begin(), arr1.end());
    if(adjecent != arr1.end())
        cout<<"Adjecent element found with value : "<<*adjecent<<endl;
    else
        cout<<"No adjecent elements are found."<<endl;
}
void test7(){
    cout<<"Test7----------------------------------------------"<<endl;
//    accumulate is from #include<numeric>
    array<int, 5>arr1{1,2,3,4,5};
    
    int sum = accumulate(arr1.begin(), arr1.end(), 0);
    cout<<"Sum of iterators in arr1 is: "<<sum<<endl;
}

void test8(){
    cout<<"Test8----------------------------------------------"<<endl;
    array<int, 10>arr1{1,3,4,3,5,3,3,3,3,6};
    int count = std::count(arr1.begin(),arr1.end(),3);
    cout<<"Found 3 "<<count<<" times."<<endl;
    
}
void test9(){
    cout<<"Test8----------------------------------------------"<<endl;
    array<int, 10>arr1{1,2,3,50,60,70,80,200,300,400};
//    Find how many numbers is between 10 and 200?
    int count = std::count_if(arr1.begin(),arr1.end(),[](int x){return x>10 && x<200;});
    cout<<"Found "<<count<<" numbers between 10 and 200"<<endl;
    
}

    int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
        test6();
        test7();
        test8();
        test9();
    return 0;
}
