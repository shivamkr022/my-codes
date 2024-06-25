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

   void insertatend(int val){   // fn to insert values at tail posn
    node *temp = new node(val);  // val = value to be added
   if(size==0)head=tail=temp;
   else {
    tail->next=temp;  // tail ke aage val laga do
    tail = temp;  // take tail to posn of temp
   }
    size++;
   }
    void insertathead(int val){   // fn to insert values head posn
    node *temp = new node(val);  // val = value to be added
   if(size==0)head=tail=temp;
   else {
    temp->next=head;  //   temp is at first posn so its next is init head
    head = temp;  //  head go to temp posn
   }
    size++;
   }
    void insertatidx(int idx,int val){  // fn to insert at any specific posn
        if(idx<0 || idx>size)cout<<"invalid"<<endl;
        else if(idx==0)insertathead(val);
        else if(idx==size)insertatend(val);
        else{
            node*t = new node(val);
            node*temp =head;
            for(int i=1;i<=idx-1;i++){  // its for creating idx-1
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }
    int getatidx(int idx){
        if(idx<0 || idx>size){
            cout<<"invalid";
            return -1;
        }
        else if(idx==0)return head->val;
        else if(idx==size-1)return tail->val;
        else{
            node*temp =head;
            for(int i=1;i<=idx;i++){  // its for going on the idx which we need
                temp=temp->next;
            }
            return temp->val;
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
};
int main(){
    linkedlist ll;
    ll.insertatend(10);
    ll.insertatend(20);
    ll.insertatend(30);

    ll.display();

    ll.insertathead(22);
    ll.display();

   // ll.insertatidx(2,80);
   // ll.display();

    cout<<ll.getatidx(3);


} 