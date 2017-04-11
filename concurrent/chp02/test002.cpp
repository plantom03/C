/*************************************************************************
	> File Name: test002.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 09时59分41秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
using namespace std;
class do_print{
public:
    void operator()()const{
        for(int i=0;i<10;i++){
            cout<<i<<endl;
        }
    }
};

int main(){
    do_print d;
    /*如果传递了一个临时变量，而不是一个命名的变量的时候，编译器
    //将会将其解析为函数的声明 而不是类型对象的定义
    //这个函数相当于声明了一个名为my_thread的函数，这个函数中带有一个参数，并且返回类型为 std::thread对象，并非启动了一个线程
    */
    //thread my_thread(do_print());
    //my_thread.join();
    /*解决方式如下：
    thread my_thread{do_print()};
    my_thread.join();*/
//也可以使用lambda表达式进行计算
    thread my_thread([]{
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        cout<<"1 from lambda"<<endl;
        });
        my_thread.detach();
    for(int i=0;i<10;i++){
        cout<<"1 from main thread"<<endl; 
    }
    return 0;
}

