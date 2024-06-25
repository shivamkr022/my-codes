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

    a.next =&b;
    b.next =&c;
    c.next =&d;

    node temp=a;  // give the val and add of a to temp node

    while(1){  // just method to print all the val
        cout<<(temp.val)<<" ";  // print all val
        if(temp.next==NULL)break; // condn till loop work
        temp=*(temp.next);  // value of next node
    }
} 