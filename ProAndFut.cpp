#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long int ull;

void findOdd(promise<ull>&& OddSumPromise,ull start,ull end){
    ull oddSum =0;
    for(ull i = start;i<=end;i++){
        if(i&1){
            oddSum+=i;
        }
    }
    OddSumPromise.set_value(oddSum);
}

int main(){
    ull start =0, end = 1900000123;
    promise<ull> OddSum;
    future<ull> OddFuture = OddSum.get_future();

    cout<<"Thread Created!!"<<endl;
    thread t1(findOdd,move(OddSum),start,end);

    cout<<"Waiting for results"<<endl;

    cout<<"OddSum :"<<OddFuture.get()<<endl;
    cout<<"Completed!"<<endl;
    t1.join();
    return 0;
}