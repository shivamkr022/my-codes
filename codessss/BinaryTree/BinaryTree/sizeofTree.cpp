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
void displaytree(Node* root){   // fn to display tree
    if(root==NULL)return;       // base case 
    cout<<root->val<<" ";       // printing value
    displaytree(root->left);     // for next values
    displaytree(root->right);
}
int sum(Node * root){
    if(root==NULL)return 0; // base case
    //int rightsum= sum(root->left);
    //int leftsum=sum(root->left);  aise v ho sakta hai
    //int sum= root->val + rightsum + leftsum;
    return root->val + sum(root->left) + sum(root->right);  // a little shortcut using reccursion
}
int size(Node * root){    // cal size
    if(root==NULL) return 0;
    return 1 + size(root->left) + size(root->right);

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
    displaytree(a);
    cout<<endl;
    cout<<sum(a)<<endl;
    cout<<size(a)<<endl;
}