#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int arr[]={10,20,-4,5,18,24,1,-7,56};  // array
    int k=4;

    priority_queue<int>pq;  // priority queue of max heap
    int n=sizeof(arr)/4;   // size of priority queue
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();
    }
    cout<<pq.top();

}