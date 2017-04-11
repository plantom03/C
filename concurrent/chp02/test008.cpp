/*************************************************************************
	> File Name: test008.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 21时50分23秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
using namespace std;
class scoped_thread{
    thread t;
public:
    //表明显式调用构造函数
    explicit scoped_thread(thread t_):t(std::move(t_)){
        if(!t.joinable()){
            throw logic_error("No thread");
        }
    }

    ~scoped_thread(){
        t.join();
    }
    scoped_thread(scoped_thread const &)=delete;
    scoped_thread & operator=(scoped_thread const&)=delete;
};

struct func{
    int & i;
    func(int & i_):i(i_){}
    void operator()(){
        for(int j=0;j<1000;j++){
            cout<<j<<"\n"<<endl;
        }
    }
};

int main(){
    int some_local_state=1000;
    scoped_thread t(thread(func(some_local_state)));
    cout<<"this is \n"<<endl;
    return 0;
}
