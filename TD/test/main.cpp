#include <iostream>
#include <string>

int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    std::cout << fibo(10) << std::endl;
    return 0;
}