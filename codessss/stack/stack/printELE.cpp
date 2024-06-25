#include<iostream>
#include<stack>
using namespace std;
int main(){

    stack<int>st;   // creating stck

    st.push(10);
    st.push(20); 
    st.push(30);  // ele of stack
    st.push(40);

    while(st.size()>0){
        cout<<st.top()<<" ";   // printing ele in reverse order
        st.pop();  // ek ek krke stack khali v kar rhe hai for always
    }
}