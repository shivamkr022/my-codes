#include<iostream>
using namespace std;
class node{   // user defined data type
    public:
    int val;
    node*next;  // store the next adddress

    node(int v){   // using constructor
        val=v;
        this->next=NULL;  // to store null addres by default
    }
};
class queue{  // user defined data structure
public:
    node *head;
    node *tail;
    int size;

    queue(){  // constructor 
    head=NULL;   // inital values 
    tail=NULL;
    size=0;
   }

   void push(int val){   // fn to insert values at tail posn
    node *temp = new node(val);  // val = value to be added
   if(size==0)head=tail=temp;
   else {
    tail->next=temp;  // tail ke aage val laga do
    tail = temp;  // take tail to posn of temp
   }
    size++;
   }
   void pop(){
    if(size==0){
        cout<<"invalid";
    }
    else{
        head=head->next;
        size--;
    }
 }
   void display(){  // fn tp display values
    node* temp=head;    
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }
   int front(){
    return head->val;
   }

};
int main(){
    queue q;   // queue
    q.push(10);
    q.push(20);    // ele of queue
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);  
    q.display();
    q.pop();
    q.pop();
    q.display();

} 