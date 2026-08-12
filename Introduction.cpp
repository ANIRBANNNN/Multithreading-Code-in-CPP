#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

//Finding the addition of all odd numbers from 1 to 1900000000 and all even numbers from 1 to 1900000000 using multithreading in C++.
ull oddSum =0;
ull evenSum =0;
void findEven(ull start, ull end){
    for(ull i=start; i<=end; i++){
        if((i&1)==0){
            evenSum += i;
        }
    }
}

void findOdd(ull start, ull end){
    for(ull i=start; i<=end; i++){
        if((i&1)==1){
            oddSum += i;
        }
    }
}

int main(){
    ull start = 0;
    ull end = 1900000000;
    auto startTime = chrono::high_resolution_clock::now();
    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);
    //findEven(start, end);
    //findOdd(start, end);
    t1.join();
     t2.join();
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout<<"Sum of all even numbers from 1 to 1900000000 is: "<<evenSum<<endl;
    cout<<"Sum of all odd numbers from 1 to 1900000000 is: "<<oddSum<<endl;
    cout<<"Time taken: "<<duration.count()<<" ms"<<endl;

    return 0;
}

//Note: Here threading takes more time as both threads are competing for the same resource (CPU) and the overhead of creating threads is more than the time taken to compute the sum. In this case, using multithreading may not provide a performance benefit.