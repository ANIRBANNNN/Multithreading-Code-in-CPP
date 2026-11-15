#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long bankBalance = 0;
mutex m;

void addMoney(long long val){
    m.lock();
    bankBalance+= val;
    m.unlock();
    cout<<bankBalance<<endl;;
}

int main(){
    thread t1(addMoney,200);
    thread t2(addMoney,300);
    t1.join();
    t2.join();
    return 0;
}