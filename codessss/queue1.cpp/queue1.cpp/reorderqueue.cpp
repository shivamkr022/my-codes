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
void reorder(queue<int>&q){
    stack<int>st;
    int n=q.size();   // size of the queue 
    for(int i=1;i<=n/2;i++){  // storing half of queue ele in stack temp
    st.push(q.front());
    q.pop();
    }
     while(st.size()>0){  // again restore ele in queue // half queue reverse now
     q.push(st.top());
     st.pop();
    }
    for(int i=1;i<=n/2;i++){  // storing 1st(2nd) half of queue ele in stack temp
    st.push(q.front());
    q.pop();
    }
    while(st.size()>0){
     q.push(st.top());
     st.pop();
     q.push(q.front());
     q.pop();
    }
    for(int i=1;i<=n;i++){  // storing  queue ele in stack temp
    st.push(q.front());
    q.pop();
    }
     while(st.size()>0){  // just reversing for the answer
     q.push(st.top());
     st.pop();
    }
}
int main(){
    queue<int>q;   // queue
    q.push(1);
    q.push(2);    // ele of queue
    q.push(3);
    q.push(4);
    q.push(5); 
    q.push(6);
    q.push(7);
    q.push(8); 

    display(q);
    cout<<endl;
   
    reorder(q);
    display(q);
}
