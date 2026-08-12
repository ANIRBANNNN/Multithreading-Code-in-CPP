//1. Function Pointer as Thread Function
#include <iostream>
#include <thread>
using namespace std;

void fun(int x){
    while(x>0){
        cout<<x<<endl;
        x--;
    }
}

int main(){
    thread t1(fun, 5);
    t1.join();
    return 0;
}