#include<iostream>
using namespace std;
class node{   // user defined data type
    public:
    int val;  // to store the values
    node*next;  // store the next adddress

    node(int v){   // using constructor
        val=v;
        this->next=NULL;  // to store null addres by default
    }
};
 void display(node*head){  // fn tp display values
    node* temp=head;    
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }
   void deletenode(node*head,node*target){  // fn to delete nodes
    node*temp=head;   //keep temp at head posn
    while(temp->next!=target){ // condn till loop work
        temp=temp->next;
    }
    temp->next=temp->next->next;  // its deletion 
   }

int main(){
     node*a = new node(10);
    node*b = new node(20);
    node*c = new node(30);
    node*d = new node(40);

    a->next=b;
    b->next=c;
    c->next=d;
    display(a);

    deletenode(a,c);
    display(a);

}