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
    // 10 20 30 40
    node a(10);
    node b(20);  // using constructor
    node c(30);
    node d(40);

   // cout<<&a<<endl;
    //cout<<a.next<<endl;

    a.next =&b;
    b.next =&c;
    c.next =&d;

    //   cout<<b.val<<endl;  // print the value of b
     //  node *ptr=&b;
    //  ptr->val=80;  // update the value using pointer
    //  cout<<b.val<<endl;

    cout<<(*(a.next)).val<<endl;  // print value of b without using b anywhere
          // or
    cout<<(a.next)->val<<endl;
} 