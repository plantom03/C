/*************************************************************************
	> File Name: test001.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 09时48分05秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
using namespace std;

void  do_print(){
    for (int i = 0;i < 10;i++ ){
        cout<<i<<endl;
    }
}

int main(){
    thread my_thread(do_print);
    //当主线程 退出之后，由其启用的线程将会随之结束
    my_thread.detach();
    return 0;
}
