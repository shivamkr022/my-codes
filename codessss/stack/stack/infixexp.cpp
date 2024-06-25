#include<iostream>
#include<stack>
using namespace std;
int pr(char ch){
    if(ch=='+' || ch=='-')return 1;  // just for priority
    else return 2;
}
int solve(int val1,int val2,int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
int main(){
    string s ="2+6*4/8-3";
    stack<int>val;
    stack<char>op;

    for(int i=0;i<s.length();i++){
         if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);  // pushing integers in val stack
         else{
            if(op.size()==0 || pr(op.top()<pr(s[i]))) op.push(s[i]); // condn of bodmas
            else{  //  pr(op.top()>=pr(s[i])
            while(op.size()==0 || pr(op.top()<pr(s[i]))){
            // ihave to do val1 op val2 // simply calculate them
            char ch = op.top();
            op.pop(); // use hote hi pop kar do
            int val2=val.top(); // get top int
            val.pop();             // pop is necessary
            int val1=val.top();  // get 2nd top ele
            val.pop();
            int ans = solve(val1,val2,ch); // return answer of that cal
            val.push(ans);
            }
            op.push(s[i]);   // no we can push next  operator
            }
       }
}
         while(op.size()>0){  // the work cont till this condn
            char ch = op.top();
            op.pop(); // use hote hi pop kar do
            int val2=val.top(); // get top int
            val.pop();             // pop is necessary
            int val1=val.top();  // get 2nd top ele
            val.pop();
            int ans = solve(val1,val2,ch); // return answer of that cal
            val.push(ans);
         }
         cout<<val.top()<<endl;  // val stack m last m answer hoga
} 