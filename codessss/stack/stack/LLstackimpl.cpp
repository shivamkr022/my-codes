#include<iostream>
using namespace std;

class node{
public:
node * next;
int val;
node(int val){ // user defined data sructure
    this->next=NULL;
    this->val=val;
   }
};

class stack{  // user defined data sructure
public:
int size;
node *head;
stack(){   // constructor
head=NULL;
size=0;
    
}
void push(int val){   // fn to push
node*temp= new node(val);
temp->next=head;
head=temp;
size++;

}
void pop(){   // fn to pop
if(head==NULL){
    cout<<"empty stack";
    return;
}
    head=head->next;
}

int top(){   // fn to get top ele
if(head==NULL){
    cout<<"empty stack";
}
return head->val;
}
void display(){
    node *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

};
int main(){
    stack st;
    st.push(10);
    st.push(20); 
    st.push(30);  // ele of stack
    st.push(40);

    st.display();

}