/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

/* includes and all */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<iomanip>
#include<cstring>
using namespace std;
vector<vector<double>>dp;
//double dp[3005][3005];
double f(vector<double>&p,int i,int x){
    if(x==0) return 1; // we got more heads than tail
    if(i==-1) return 0;
    if(dp[i][x]> -0.9) return dp[i][x];
    return dp[i][x] = f(p,i-1,x-1)*p[i] + f(p,i-1,x)*(1-p[i]);
}

int main(){
    int n;
    cin>>n;
    vector<double>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    //memset(dp,-1,sizeofdp);
    dp.clear();
    dp.resize(3005,vector<double>(3005,-1));
    cout<<fixed<<setprecision(9)<<f(p,n-1,(n+1)/2);
    return 0;
}