/*************************************************************************
	> File Name: test006.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月11日 星期二 14时31分27秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
#include<functional>
using namespace std;
class X{
public:
    void length_work(int c){
    cout<<"this is a test from thread "<<c<<endl;
    cout<<x++<<endl;
    };
private:
    int x=0;
};

int main(){
    X my_x;
    X se_x;
    int num(0);
    thread t(&X::length_work,&my_x,num);
    int num1(1);
    thread t1(&X::length_work,&se_x,num);
    t.join();
    t1.join();
    return 0;
}
