#include<iostream>
using namespace std;
class Node{
public:        // user defined data structure
int val;
Node *left;
Node* right;  

Node(int val){
    this->val=val;
    this->left=NULL;   // constructor
    this->right=NULL;
  }
};
void nthlevel(Node* root,int curr, int level){   // fn to display tree
    if(root==NULL)return;       // base case 
    if(curr==level)cout<<root->val<<" ";       // printing value // kaam // one more condn
    nthlevel(root->left,curr+1,level);     // call 1
    nthlevel(root->right,curr+1,level);    // call 2
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);    // values of tree nodes
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left=b;
    a->right=c;   // connecting a/q to questions
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    nthlevel(a,1,3);

}