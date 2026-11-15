#include<iostream>
#include<bits/stdc++.h>
using namespace std;

mutex m1;
mutex m2;
mutex m3;
mutex m4;

void task_a(){
    while(1){
        lock(m1,m2);
        lock(m3,m4);
        cout<<"task a\n";
        m1.unlock();
        m2.unlock();
        m3.unlock();
        m4.unlock();
    }
}
void task_b(){
    while(1){
        lock(m3,m4);
        lock(m1,m2);
        cout<<"task b\n";
        m3.unlock();
        m4.unlock();
        m1.unlock();
        m2.unlock();
    }
}

int main(){
    thread t1(task_a);
    thread t2(task_b);
    t1.join();
    t2.join();
    return 0;
}