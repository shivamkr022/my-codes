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
class linkedlist{  // user defined data structure
public:
    node *head;
    node *tail;
    int size;

    linkedlist(){  // constructor 
    head=NULL;   // inital values 
    tail=NULL;
    size=0;
   }

   void insertatend(int val){   // fn to insert values
    node *temp = new node(val);  // val = value to be added
   if(size==0)head=tail=temp;
   else {
    tail->next=temp;  // tail ke aage val laga do
    tail = temp;  // take tail to posn of temp
   }
    size++;
   }

   void display(){  // fn tp display values
    node* temp=head;    
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }
};
int main(){
    linkedlist ll;
    ll.insertatend(10);
    ll.insertatend(20);
     cout<<ll.size<<endl;
    ll.display();
    ll.insertatend(30);
    ll.display();
    cout<<ll.size<<endl;
} 