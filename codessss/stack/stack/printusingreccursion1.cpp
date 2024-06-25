#include<iostream>
#include<stack>
using namespace std;
void displayrec(stack<int> & st){
    if(st.size()==0)return;  // base case
    int x = st.top();   // store kara liye x me
    st.pop();     // delete
    displayrec(st);   // call laga diya 
     cout<<x<<" ";  // print 
    st.push(x);  
}

int main(){
    stack<int>st;   // creating stck

    st.push(10);
    st.push(20); 
    st.push(30);  // ele of stack
    st.push(40);

    displayrec(st);   // calling our fn  // reverse order print
}