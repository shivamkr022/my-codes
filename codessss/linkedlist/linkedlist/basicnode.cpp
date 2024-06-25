#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node*next;  // store the next adddress

};
int main(){
    // 10 20 30 40
    node a;
    a.val=10;
    node b;
    b.val=20;
    node c;
    c.val=30;
    node d;
    d.val=40;

    //forming linked list

    a.next =&b;
    b.next =&c;
    c.next =&d;
    d.next =NULL;
} 