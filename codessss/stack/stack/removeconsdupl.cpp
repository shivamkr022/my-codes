#include<iostream>
#include<algorithm>
#include<stack>   
using namespace std;

string removedup(string s){
    stack<char> st;
    st.push(s[0]);   // first ele to always push hoga hi
    for(int i=1;i<=s.length();i++){
     if(s[i]!=st.top()) st.push(s[i]);
    }
    s="";  // empty string to store values
    while(st.size()>0){  // we take all ele from 
        s+=st.top();   // we store ele one by one
        st.pop();
    }
    reverse(s.begin(),s.end()); // just for the answer
    return s;
}
int main(){
    string s="aabbccddeeff";
    cout<<s<<endl;
    s=removedup(s);
    cout<<removedup(s);
}