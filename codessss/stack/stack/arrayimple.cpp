#include<iostream>
using namespace std;

class stack{  // user defined data sructure
public:

int arr[5];
int idx;

stack(){   // constructor
    idx=-1;
}
void push(int val){   // fn to push
    idx++;
    arr[idx]=val;
}
void pop(){   // fn to pop
    idx--;
}
int size(){    // fn to cal size
    return idx+1;
}
int top(){   // fn to get top ele
    return arr[idx];
}
};
int main(){
    stack st;
    st.push(10);
    st.push(20); 
    st.push(30);  // ele of stack
    st.push(40);

    cout<<st.size()<<endl;
    st.push(60);
    cout<<st.size()<<endl;
}