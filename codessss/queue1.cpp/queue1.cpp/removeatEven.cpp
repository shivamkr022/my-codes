#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>&q){
    int n=q.size();   // size of the queue
    for(int i=1;i<=n;i++){
        int x=q.front();   // store the ele in x
        cout<<q.front()<<" ";   // printing front ele
        q.pop();   // deleting front ele
        q.push(x);  // again push ele which has printed
    }
}
void removeateven(queue<int>&q){
    int n=q.size();   // size of the queue
    for(int i=0;i<n;i++){
       if(i%2==0){
        q.pop();
       }
       else{
        int x=q.front();
        q.pop();
        q.push(x);
       }
    }
}
int main(){
    queue<int>q;   // queue
    q.push(10);
    q.push(20);    // ele of queue
    q.push(30);
    q.push(40);
    q.push(50);  
    q.push(60); 

    display(q);
    cout<<endl;
    removeateven(q);
    display(q);
}
