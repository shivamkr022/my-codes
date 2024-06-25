#include<iostream>
using namespace std;
class node{   // linked list node
    public:
    int val;
    node*next;  // store the next adddress

    // using constructor
    node(int v){
        val=v;
        this->next=NULL;  // to store null addres by default

    }
};
int main(){
    node*a = new node(10);
    node*b = new node(20);
    node*c = new node(30);
    node*d = new node(40);

    a->next=b;
    b->next=c;
    c->next=d;

    node* temp=a;  
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;

    }
} 