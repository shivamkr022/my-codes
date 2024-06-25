#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> >pq;  // min heap
    pq.push(10);
    pq.push(25);
    pq.push(-6);  // adding ele
    pq.push(81);

    cout<<pq.top()<<endl;  // -6 aayega
    pq.pop();   // removed -6
    cout<<pq.top()<<endl;  // 10
}