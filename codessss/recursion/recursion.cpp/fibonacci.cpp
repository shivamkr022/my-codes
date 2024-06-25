#include<iostream>
using namespace std;
int fib(int x){
    if(x==0 || x==1){
        return x;
    }
    return fib(x-2)+fib(x-1);
}
int main(){
    cout<<fib(4)<<endl;
}