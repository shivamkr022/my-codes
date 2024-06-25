#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
    long long dp[2005][2005][8];  // 2d dp

    long long f(int *s1,int *s2,int n, int m,int i,int j , int k){ //  fn to return length of lcs
   
        if(i==n) return 0;  // base case
        if(j==m) return 0; // base case
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long res=0;
        if(s1[i]==s2[j]){  // equal 
            res = 1+f(s1,s2,n,m,i+1,j+1,k); 
        }
        else {
            if(k>0){
            res = 1+f(s1,s2,n,m,i+1,j+1,k--); // reccursive relation
            }
             res = max(res,f(s1,s2,n,m,i+1,j,k));
              res = max(res,f(s1,s2,n,m,i,j+1,k));
        }
        dp[i][j][k]=res;
        return res;
    }
int main(){

}