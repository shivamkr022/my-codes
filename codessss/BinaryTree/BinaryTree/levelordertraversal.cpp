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
int levels(Node * root){
    if(root==NULL)return 0;
    return 1+ max(levels(root->left),levels(root->right));
}
void nthlevel(Node* root,int curr, int level){   // fn to display tree
    if(root==NULL)return;       // base case 
    if(curr==level)cout<<root->val<<" ";       // printing value // kaam // one more condn
    nthlevel(root->left,curr+1,level);     // call 1
    nthlevel(root->right,curr+1,level);    // call 2
}
void levelorder(Node* root){   // fn to display tree
int n=levels(root);
for(int i=1;i<=n;i++){
    nthlevel(root,1,i);
    cout<<endl;
}
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
    c->right=g;
    levelorder(a);

}