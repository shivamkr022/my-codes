#include<iostream>
using namespace std;
int main(){
    int arr[10]={0,1,2,5,9,15,17,18,21,24};
    int n=10;

    int lo=0;
    int hi=n-1;
    int ans=-1;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid)lo=mid+1;
        else{
            ans = mid;
            hi=mid-1;
        }
    }
    cout<<ans;
}
