/*************************************************************************
	> File Name: test004.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 10时55分24秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
using namespace std;
//使用rall等待线程完成
class thread_guard{
    thread& t;
public:
    explicit thread_guard(thread& t_):t(t_){}
    ~thread_guard(){
        if(t.joinable()){
            t.join();
        }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard)=delete;
};
truct func{
        int& i;
        func(int & i_):i(i_){}
    void operator()(){
        for(unsigned j=0;j<100000;++j){
                        cout<<i<<endl;
                    
        }
            
    }

};

void f(){
    int some_local_state=0;
    func my_func(some_local_state);
    thread t(my_func);
    thread_guard g(t);
    
}
