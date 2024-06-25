#include<iostream>
using namespace std;
void hanoi(int n,char a,char b,char c){
    if(n==0)return;
    hanoi(n-1,a,c,b);  // n-1 ko b p rakhne k liye
    cout<<a<<"-->"<<c<<endl; // a ko c pe rakha
    hanoi(n-1,b,a,c); // n-1 ko c p rakhne k liye

}
int main(){
    int n=3;
    hanoi(n,'A','B','C');

}