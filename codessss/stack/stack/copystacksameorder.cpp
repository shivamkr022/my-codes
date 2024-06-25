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
        temp.push(st.top()); // store ele of stack in temp
        st.pop();  // ek ek krke stack khali v kar rhe hai for always
    }
   
     stack<int>temp1;  // copy ele in same order like in st
     while(temp.size()>0){
        temp1.push(temp.top());
        temp.pop();
     }
      while(temp1.size()>0){    // print the same order as of st
        cout<<temp1.top()<<" ";
        temp1.pop();
    }
}
