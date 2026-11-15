#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long int ull;

ull findOdd(ull start,ull end){
    ull oddSum =0;
    cout<<"Thread ID of findOdd()"<<this_thread::get_id()<<endl;
    for(ull i = start;i<=end;i++){
        if(i&1){
            oddSum+=i;
        }
    }
    return oddSum;
}

int main(){
    ull start =0, end = 19000000;
    cout<<"ThreadID of main is "<<this_thread::get_id()<<endl;
    cout<<"Thread Created!!"<<endl;

    future<ull> OddSum = async(launch::deferred,findOdd,start,end);

    cout<<"Waiting for results"<<endl;
    cout<<"OddSum : "<<OddSum.get()<<endl;
    cout<<"Completed!!"<<endl;
    return 0;

}