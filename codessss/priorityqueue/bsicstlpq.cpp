#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq;  // priority queue of max heap
    pq.push(10);
    pq.push(25);
    pq.push(-6);  // adding ele
    pq.push(81);

    cout<<pq.top()<<endl;  // 81 aayega
    pq.pop();   // removed 81
    cout<<pq.top()<<endl;  // 25


}