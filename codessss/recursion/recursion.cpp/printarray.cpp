#include<iostream>
using namespace std;
void f(int arr[],int idx,int n){
    if(idx==n)return; // base case
    cout<<arr[idx]<<endl;
    
    f(arr,idx+1,n);

}
int main(){
    int arr[]={1,5,3,6,8,5,4};
    int n=7;
    f(arr,0,n);

}