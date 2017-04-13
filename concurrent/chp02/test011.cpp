/*************************************************************************
	> File Name: test011.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月12日 星期三 15时47分46秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
using namespace std;

std::thread::id master_thread;

void do_print(){
    if(std::this_thread::get_id()==master_thread){
        printf("this is from master_thread\n");
        thread t1(do_print);
        t1.join();
        
    }

    printf("Hello world\n");
    cout<<std::this_thread::get_id();
}

int main(){
    thread t1(do_print);
    master_thread=t1.get_id();
    t1.join();
    return 0;
}
