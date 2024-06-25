#include<iostream>
#include<vector>
using namespace std;
class queue{   // user defined ds
public:
int f;
int b;
vector<int>arr;   // an empty vector
queue(int val){   // constructor
    f=0;
    b=0;
    vector<int>v(val);   // vector of size val
    arr=v;  // arr and v are same
}
void push(int val){
    if(b==arr.size()){
        cout<<"queue is full";
    }
    arr[b]=val;  // push in queue
    b++;   
}
void pop(){
    if(b==5){
        cout<<"queue is full";
    }
    f--;
}
int frontt(){
    return arr[f];
}
int back(){
    return arr[b-1];
}
int size(){
    return b-f;
}
void display(){
    for(int i=f;i<b;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }
};

int main(){
    queue q(5);   // queue
    q.push(10);
    q.push(20);    // ele of queue
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);  
    q.display();
    q.pop();
    
}
