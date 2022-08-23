//
//  main.cpp
//  for_each algo STL using lambda expression
//
//  Created by Amartya Vibhu on 23/08/22.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int>vec{1,2,3,4};
    for_each(vec.begin(),vec.end(), [](int x){cout<<x * x<<" ";});
    return 0;
}
