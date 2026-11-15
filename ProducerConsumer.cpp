#include<iostream>
#include<bits/stdc++.h>
using namespace std;

mutex mu;
condition_variable cond;
deque<int>buffer;
const unsigned int maxBufferSize = 50;

void producer(int val){
    while(val>0){
        unique_lock<mutex> locker(mu);
        if(buffer.size()>=maxBufferSize){
            cond.wait(locker);
        }
        buffer.push_back(val);
        cout<<"Produced"<<val<<endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer(){
    while(true){
        unique_lock<mutex>locker(mu);
        if(buffer.size()>0){
            cond.wait(locker);
        }
        int val = buffer.back();
        buffer.pop_back();
        cout<<"Consumed"<<val<<endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main(){
    thread t1(producer,100);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}