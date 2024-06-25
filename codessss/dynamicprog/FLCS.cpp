#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>>dp;  // 2d dp
string ans="";
    int f(string&s1,string&s2,int i,int j , string output){ //  fn to return length of lcs
    if(output.length()>ans.length()) ans=output;
        if(i>=s1.length()) return 0;  // base case
        if(j>=s2.length()) return 0; // base case
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){  // equal 
            return dp[i][j] = 1+f(s1,s2,i+1,j+1,output+s1[i]); 
        }
        else{
            return dp[i][j] = max(f(s1,s2,i+1,j,output),f(s1,s2,i,j+1,output)); // reccursive relation
        }
    }
int main(){
    string s1,s2;
    cin>>s1>>s2;
        dp.clear();
        dp.resize(1005,vector<int>(1005,-1));
        f(s1,s2,0,0,"");
        cout<<ans;
        return 0;
}