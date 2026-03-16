#include<iostream>
using namespace std;
int add(int a, int b){
    return a+b;
}
int main(){
    int x,y;
    cin>>x>>y;
    int sum = add(x,y);
    cout<<sum<<endl;
}