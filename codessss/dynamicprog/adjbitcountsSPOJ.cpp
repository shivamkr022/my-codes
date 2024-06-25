#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
int dp[1005][105][2];
int f(int n,int k,int last){
    if(n==0) return 0; // base case
    if(n==1 && k<0) return 0;
    if(n==1 && k==0) return 1; // base case
    if(dp[n][k][last]!=-1) return dp[n][k][last];
    if(last==1){
       return dp[n][k][last] = f(n-1,k,0)+f(n-1,k-1,1);  // reccursion relation
    }
    else if(k==0){
     return dp[n][k][last] = f(n-1,k,0)+f(n-1,k,1);    // reccursion relation
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp,-1,sizeof dp);
        int ans= f(n,k,0)+f(n,k,1);
        cout<<num<<" "<<ans<<"\n";
    }
    return 0;

}