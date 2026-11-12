#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int counter = 0;
mutex mtx;
void increaseTheCounter(){
    for(int i =0;i<100000;i++){
    if(mtx.try_lock()){
        ++counter;
        mtx.unlock();
    }
    }
}
int main(){
    thread t1(increaseTheCounter);
    thread t2(increaseTheCounter);

    t1.join();
    t2.join();
    cout<<counter<<endl;
}