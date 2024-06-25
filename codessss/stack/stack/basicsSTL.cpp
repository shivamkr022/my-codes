#include<iostream>
#include<stack>
using namespace std;
int main(){

    stack<int>st;   // creating stck

    cout<<st.size()<<endl; // here size is 0

    st.push(10);
    st.push(20);  // adding elements
    st.push(30);
    st.push(40);

    cout<<st.size()<<endl;  // here size is 4

    st.pop();   // we remove 40 // lifo

    cout<<st.size()<<endl;  // here size is 3

    cout<<st.top()<<endl; // here we print 30 

}

