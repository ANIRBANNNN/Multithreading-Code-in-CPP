#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int myAmount = 0;
timed_mutex m;

void increment(int i){
    auto now = chrono::steady_clock::now();
    if(m.try_lock_until(now + chrono::seconds(1))){
        myAmount++;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"Thread "<<i<<"Entered"<<endl;
        m.unlock();
    }
    else{
        cout<<"Thread "<<i<<"Couldn't Enter"<<endl;
    }
}
int main(){
    thread t1(increment,1);
    thread t2(increment,2);
    t1.join();
    t2.join();
    return 0;
}