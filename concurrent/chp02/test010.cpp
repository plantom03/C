/*************************************************************************
	> File Name: test010.cpp
	> Author: habit
	> Mail: platom03@163.com
	> Created Time: 2017年04月12日 星期三 09时01分24秒
 ************************************************************************/

#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<thread>
#include<vector>
#include<iterator>
#include<numeric>
#include<algorithm>
using namespace std;

template<typename Iterator,typename T>
struct accmulate_block{
    void operator()(Iterator first,Iterator last,T& result){
        result=accmulate(first,last,result);
    }
};

template<typename Iterator,typename T> 
T parallel_accumulate(Iterator first,Iterator last,T init){
    unsigned long const length=distance(first,last);
    if(!length)
        return init;
    
    unsigned long const min_per_thread=25;
    unsigned long const max_threads=(length+min_per_thread-1)/min_per_thread;

    unsigned long const hardware_threads=thread::hardware_concurrency();

    unsigned long const num_threads= std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    
    unsigned long const block_size=length/num_threads;
    
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);

    Iterator block_start=first;

    for(unsigned long i=0;i<(num_threads -1);++i){
        Iterator block_end=block_start;
        advance(block_end,block_size);
        threads[i]=std::thread(
            accmulate_block<Iterator,T>(),
            block_start,block_end,std::ref([results[i]]));
            block_start=block_end;
    }

    accmulate_block<Iterator,T>()(block_start,last,results[num_threads-1]);

    for_each(threads.begin(),threads.end(),std::mem_fn(&thread::join));

    return accmulate(results.begin(),results.end(),init);
}

int main(){
    unsigned int lenth=thread::hardware_concurrency();
    cout<<lenth<<endl;
    return 0;
}
