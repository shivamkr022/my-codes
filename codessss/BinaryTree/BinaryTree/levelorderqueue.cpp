#include<iostream>
#include<queue>
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

void levelorderque(Node *root){
    queue<Node*> q;  // que of node type
    q.push(root);    // pushing root
    while(q.size()>0){
    Node *temp=q.front();   // store front 
    q.pop();                // pop it
    cout<<temp->val<<" ";   // print it
    if(temp->left!=NULL)q.push(temp->left);   // to print all val
    if(temp->right!=NULL)q.push(temp->right); // to print all val in a sequence
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
    levelorderque(a);

}