#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    thread t([](int x){
        while(x>0){
            cout<<x<<endl;
            x--;
        }
    },10);
    t.join();
    return 0;
}

