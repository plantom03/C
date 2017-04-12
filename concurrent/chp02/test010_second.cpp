/*************************************************************************
	> File Name: test010_second.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月12日 星期三 11时16分51秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
#include<numeric>
#include<algorithm>
#include<vector>
using namespace std;

struct accumulate_block{
    void operator()(vector<int>::iterator first,
                    vector<int>::iterator last,
                    int & result){
    result=std::accumulate(first,last,result);
    }
};

int parallel_accumate(vector<int>::iterator first,vector<int>::iterator last,int init){
    unsigned long const lenth=std::distance(first,last);

    if(!lenth)//判断开始迭代器和最终迭代器是不是同一个是的话不进行迭代
        return init;

    unsigned long const min_per_thread=25;//计算每个线程的最小处理的数据量

    unsigned long const max_threads=(lenth+min_per_thread-1)/min_per_thread;

    unsigned long const hardware_threads=thread::hardware_concurrency();

    unsigned long const num_threads=std::min(hardware_threads!=0?hardware_threads :2,max_threads);

    unsigned long const block_size=lenth/num_threads;

    vector<int> results(num_threads);
    
    vector<thread> threads(num_threads-1);
    
    vector<int>::iterator block_start=first;
    
    for(unsigned long i=0;i<(num_threads-1);++i){
        vector<int>::iterator block_end=block_start;
        advance(block_end,block_size);
        threads[i]=thread(accumulate_block(),block_start,block_end,std::ref(results[i]));
        block_start=block_end;
    }

    accumulate_block()(block_start,last,results[num_threads-1]);
    for_each(threads.begin(),threads.end(),std::mem_fn(&thread::join));
    return accumulate(results.begin(),results.end(),init);
}

int main(){
    vector<int> vec;

    for(int i=0;i<100000000;i++){
        vec.push_back(i);
    }

    cout<<parallel_accumate(vec.begin(),vec.end(),0);

    return 0;
}
