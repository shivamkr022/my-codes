#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int arr[]={6,5,3,2,8,10,9};  // array

    priority_queue<int, vector<int> ,greater<int> >pq;  // priority queue of min heap
    vector<int>ans;  // to store the ans
    int n=sizeof(arr)/sizeof(arr[0]);   // size of priority queue
    for(int i=0;i<n;i++){
        pq.push(arr[i]);  // pq me sab ele push kr diye
    }
    while(pq.size()>0){  
            ans.push_back(pq.top());
            pq.pop();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}