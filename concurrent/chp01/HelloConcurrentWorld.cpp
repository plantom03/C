/*************************************************************************
	> File Name: HelloConcurrentWorld.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 09时10分43秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
//在C++11的标准库中增加了对多线程的支持
using namespace std;
void hello(){
    cout<<"Hello Concurrent World \n";
}

int main(){
    //新的线程启动了之后，初始线程将会继续进行执行
    thread t(hello);
    //增加了t将会在初始线程中 等待被调用线程的执行
    t.join();
    return 0;
}
