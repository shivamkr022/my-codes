#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> st){
    stack<int>temp; 
        while(st.size()>0){   
        temp.push(st.top()); // store ele of stack in temp
        st.pop();  // ek ek krke stack khali v kar rhe hai for always
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
}
void pushatbottom(stack<int> &st, int val){
    stack<int>temp; 
        while(st.size()>0){   
        temp.push(st.top()); // store ele of stack in temp
        st.pop();  // ek ek krke stack khali v kar rhe hai for always
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int>st;   // creating stck

    st.push(10);
    st.push(20); 
    st.push(30);  // ele of stack
    st.push(40);

    print(st);
    cout<<endl;

    pushatbottom(st, 50);
        print(st);

}
