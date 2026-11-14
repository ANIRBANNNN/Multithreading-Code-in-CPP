#include<iostream>
#include<bits/stdc++.h>
using namespace std;

condition_variable cv;
mutex m;
long balance = 0;

void addMoney(int amount){
    lock_guard<mutex> lg(m);
    balance+= amount;
    cout<<"Amount added after cureent balance: "<<balance<<endl;
    cv.notify_one();
}

void withdrawMoney(int amount){
    unique_lock<mutex> ul(m);
    if(balance == 0) cv.wait(ul);
    if(balance>= amount){
        balance -= amount;
        cout<<"Amount deducted:"<<amount<<endl;
    }
    else{
        cout<<"Amount can't be deducted as amount is less than "<<amount<<endl;
    }
    cout<<"Current amount is "<<balance<<endl;
}
int main(){
    thread t1(withdrawMoney,1000);
    this_thread::sleep_for(chrono::seconds(5));
    thread t2(addMoney,1500);
    t1.join();
    t2.join();
    return 0;
}