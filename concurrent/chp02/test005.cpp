/*************************************************************************
	> File Name: test005.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 13时50分18秒
向线程函数传递参数
************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
#include<functional>
#include<stdio.h>
using namespace std;
void f(int n,string & s){
    for(int i=0;i<n;i++){
        cout<<s<<endl;
    }
    s="this is a test005.cpp";
}

void oops(int some_param){
    //string test="this is ";
    char buffer[1024];
    sprintf(buffer,"%i",some_param);
    //使用string为了避免在转换的时候 buffer 还没有转换为一个
    //string，就导致了变量的销毁
    //使用一个ref 是为了实现传递的时候 传递了一个引用 
    //便于进行值的 更新
    string test(buffer);
   cout<<test<<endl;
    thread t(f,3,std::ref(test));
    t.join();
    cout<<test<<endl;
}

int main(){
    oops(12);
    return 0;
}
