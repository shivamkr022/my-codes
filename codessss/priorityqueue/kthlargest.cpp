#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int arr[]={10,200,-4,6,18,2,105,118};  // array
    int k=3;

    priority_queue<int, vector<int> ,greater<int> >pq;  // priority queue of min heap
    int n=sizeof(arr)/4;   // size of priority queue
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();
    }
    cout<<pq.top()<<endl;  // 81 aayega
}