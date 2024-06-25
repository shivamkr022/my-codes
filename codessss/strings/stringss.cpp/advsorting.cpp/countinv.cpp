#include<iostream>
using namespace std;
int main(){
    int arr[7]={5,1,3,0,4,6,9};
    int n=7;
    int count =0;
    for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j] && i<j)count++;
         }
    }
    cout<<count<<endl;
}