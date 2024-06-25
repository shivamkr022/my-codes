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
void display(node* head){  // fn tp display values
    node* temp=head;    
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
int size(node*head){  // for counting total number of values
     node* temp=head;  
     int n=0;  
    while(temp!=NULL){

        temp=temp->next;
         n++;
    }
    return n;
}
void recdisplay(node*head){
    if(head==NULL) return;  // base case
        cout<<head->val<<endl;  // kaam     // print using reccursioin
        recdisplay(head->next);  // call
}

void recdisplayrev(node*head){
    if(head==NULL) return;  // base case
     recdisplay(head->next);  // call 
        cout<<head->val<<endl; // kaam    // print in reverse order
}
int main(){
    node*a = new node(10);
    node*b = new node(20);
    node*c = new node(30);
    node*d = new node(40);

    a->next=b;
    b->next=c;
    c->next=d;

    recdisplay(a);
    recdisplayrev(a);

} 