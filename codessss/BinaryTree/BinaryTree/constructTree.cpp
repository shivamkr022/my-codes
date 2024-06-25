#include<iostream>
#include<algorithm>
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
Node*construct(int arr[],int n){
    queue<Node*> q;  // que of node type
    Node *root= new Node(arr[0]);   // first ele always root hoga
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
    Node *temp=q.front();   // store front 
    q.pop();                // pop it
    Node *l;
    Node *r;
    if(arr[i]!=INT16_MIN) l= new Node(arr[i]);  // left connection 
    else l=NULL;

    if(j!=n && arr[j]!=INT16_MIN) r= new Node(arr[j]);  // right connection 
    else r=NULL;

    temp->left=l;  // connecting nodess
    temp->right=r;

    if(l!=NULL)q.push(l);
    if(r!=NULL)q.push(r);
    i+=2;  // just iteration
    j+=2;
    }
    return root;
}

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
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,INT16_MIN,6,INT16_MIN,INT16_MIN,7,8,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    Node*root= construct(arr,n);
    levelorderque(root);  // for displaying our tree

}