#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void run(int count){
    while(count-->0)
        cout<< count<<"Anirban"<<endl;
        //this_thread::sleep_for(chrono::seconds(5));
    
}
int main(){
    thread t1(run,10);
    cout<<"Thread opening"<<endl;
    //t1.detach();
    cout<<"Thread closing"<<endl;
    return 0;
}