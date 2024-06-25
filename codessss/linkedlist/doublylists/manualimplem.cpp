#include<iostream>
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
void display(node * head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    node*a= new node(10);
    node*b= new node(20);
    node*c= new node(30);
    node*d= new node(40);
    node*e= new node(50);

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    e->prev=d;
    d->prev=c;
    c->prev=b;
    b->prev=a;

    display(a);


}