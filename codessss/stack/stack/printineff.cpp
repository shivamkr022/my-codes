#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;   // creating stck

    st.push(10);
    st.push(20); 
    st.push(30);  // ele of stack
    st.push(40);

    stack<int>temp;   // creating stck for storing ele of stack temporarily

    while(st.size()>0){
        cout<<st.top()<<" ";   // printing ele in reverse order
        int x=st.top(); // store the ele in x
        st.pop();  // ek ek krke stack khali v kar rhe hai for always
        temp.push(x); // store ele of stack in temp
    }
    while(temp.size()>0){
        int x= temp.top();  // top ele ko store kar liya x var me
        temp.pop();   // del ele of temp one by one 
        st.push(x);   // add ele one by one in stack st
    }
    cout<<endl;
    
     cout<<st.top()<<" ";
}