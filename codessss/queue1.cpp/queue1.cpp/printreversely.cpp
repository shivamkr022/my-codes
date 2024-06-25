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
void reverse(queue<int>&q){
    stack<int>st;
 
    while(q.size()>0){  // storing ele in stack temp
        int x = q.front();
        q.pop();
        st.push(x);
    }
     while(st.size()>0){  // again restore ele in queue // it reverse now
        int x = st.top();
        st.pop();
        q.push(x);
    }
}
int main(){
    queue<int>q;   // queue
    q.push(10);
    q.push(20);    // ele of queue
    q.push(30);
    q.push(40);
    q.push(50);  

    display(q);
    cout<<endl;
    reverse(q);
    display(q);
}
