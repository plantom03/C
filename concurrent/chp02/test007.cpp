/*************************************************************************
	> File Name: test007.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 21时24分26秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
using namespace std;

void printA(){
    cout<<"this is a output from A thread\n"<<endl;
}

void printB()
    {
    cout<<"this is a output from B thread\n"<<endl;
}

int main(){
    thread t1(printA);
    thread t2=move(t1);
    t1=thread(printB);
    thread t3;
    t3=move(t2);
    t2=move(t3);
    t1.join();
    t2.join();
    //t3.join();
    return 0;
}
