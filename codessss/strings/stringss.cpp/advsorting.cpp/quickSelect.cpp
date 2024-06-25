#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei){
    int pivotele=arr[(si+ei)/2];
    int count =0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2)continue;
        if(arr[i]<=pivotele)count++;
    }
    int pivotidx=count+si;
    swap(arr[(si+ei)/2],arr[pivotidx]);
    int i=si;
    int j=ei;
    while(i<pivotidx && j>pivotidx){
        if(arr[i]<=pivotele)i++;
        if(arr[j]>pivotele)j--;
        else if(arr[i]>pivotele && arr[j]<=pivotele){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;

}
int kthsmallest(int arr[],int si,int ei,int k){
    int pi=partition(arr,si,ei);
    if(pi+1==k)return arr[pi];
    else if(pi+1 <k)return  kthsmallest(arr,pi+1,ei,k);
    else return  kthsmallest(arr,si,pi-1,k);
    
}
int main(){
    int arr[]={5,1,8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        }
        cout<<endl;
        int k=4;
    cout<<kthsmallest(arr,0,n-1,k);
  
}
