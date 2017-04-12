/*************************************************************************
	> File Name: test009.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月12日 星期三 08时48分43秒
>线程内部的局部变量 并不会在线程之间进行共享
可以通过创建一组线程完成线程的管理
************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<vector>
#include<thread>
#include<stdio.h>
#include<algorithm>

using namespace std;
void do_work(unsigned int id){
    int i=0;
    printf("%d %d\n",id,++i);
    
}

void f(){
    vector<thread> threads;
    for(unsigned int i=0;i<20;++i){
        threads.push_back(thread(do_work,i));
    }

    for_each(threads.begin(),threads.end(),mem_fn(&thread::join));
}

int main(){
    f();
    return 0;
}

