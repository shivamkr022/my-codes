#include<iostream>
using namespace std;
int main(){
    int arr[]={5,2,3,6,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    int i=0;
    while(i<n){
        int correctidx=arr[i]-1;
        if(i==correctidx)i++;
        else swap(arr[i],arr[correctidx]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}