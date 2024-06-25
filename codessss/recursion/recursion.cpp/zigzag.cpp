#include<iostream>
using namespace std;
void zigzag(int x){

    if(x==0)return;
    cout<<x;
    zigzag(x-1);
    cout<<x;
    zigzag(x-1);
    cout<<x;
}
int main(){
    cout<<endl;
    zigzag(2);
    cout<<endl;
}