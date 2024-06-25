/*#include<iostream>
using namespace std;
class node{   // user defined data type
    public:
    int val;
    node*next;  // store the next adddress
    node*prev;  // store prev add

    node(int v){   // using constructor
        val=v;
        this->next=NULL;  // to store null addres by default
        this->prev=NULL;
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
   void pushBack(int val){   // fn to insert values at tail posn
    node *temp = new node(val);  // val = value to be added
   if(size==0)head=tail=temp;
   else {
    tail->next=temp;  // tail ke aage val laga do
    temp->prev=tail;
    tail = temp;  // take tail to posn of temp
   }
    size++;
}
void pushfront(int val){   // fn to insert values head posn
    node *temp = new node(val);  // val = value to be added
   if(size==0)head=tail=temp;
   else {
    temp->next=head;  //   temp is at first posn so its next is init head
    head->prev=temp;
    head = temp;  //  head go to temp posn
   }
    size++;
   }
    void pop(){
    if(size==0){
        cout<<"invalid";
        return;
    }
    else{
        head=head->next;
        if(head)head->prev=NULL;
        if(head==NULL) tail=NULL;
        size--;
}
  void deleteatatil(){
    if(size==0){
        cout<<"invalid";
        return;
    }
    else{
        if(size==1)pop;

        }
        cout<<endl;
    }
void display(node * head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
  }
};
int main(){


}