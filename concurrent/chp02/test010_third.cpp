/*************************************************************************
	> File Name: test010_third.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月12日 星期三 14时08分15秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int accumulatenum(vector<int>::iterator first,vector<int>::iterator last,int init){
    int length = distance(first,last);
    if(!length)
        return init;

    return accumulate(first,last,init);
}

int main(){
    vector<int> vec;
    for(int i=0;i<100000000;i++){
        vec.push_back(i);
    }
    cout<<accumulatenum(vec.begin(),vec.end(),0);
}
