/*************************************************************************
	> File Name: test003.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 10时27分52秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;
struct func{
    int& i;
    func(int & i_):i(i_){}
    void operator()(){
        for(unsigned j=0;j<100000;++j){
            cout<<i<<endl;
        }
    }
};
void oops(){
    int some_local_state=0;
    func my_func(some_local_state);
    thread my_thread(my_func);
    my_thread.detach();
};

void f(){
    int some_local_state=0;
    func my_func(some_local_state);
    thread t(my_func);
    try{
        
    }catch(){
        t.join();
        throw;
    }
    t.join();
} 

int main(){
    oops();
    sleep(10);
    return 0;
}

