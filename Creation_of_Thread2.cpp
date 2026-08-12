//Through Lambda Function
#include <iostream>
#include <thread>   
int main(){
    auto fun = [](int x){
        while(x>0){
            std::cout<<x<<std::endl;
            x--;
        }
    };
    std::thread t1(fun, 5); 
    t1.join();
    return 0;
}