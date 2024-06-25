#include<iostream>
#include<stack>   // leetcode problem que 20
using namespace std;

bool isbalanced(string s){
    if(s.length()%2!=0)return false; // odd length cant be balanced ever

    stack<char>st; // character stack
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(s[i]);
        else{  // s[i]=')'
        if(st.size()==0)return false;
        else st.pop(); // yaha open bracket hi hga
        }
    }
    if(st.size()==0) return true;
    else return false;
}

int main(){
    string s="(())";
    cout<<isbalanced(s);

}