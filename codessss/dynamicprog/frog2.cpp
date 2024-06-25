#include<iostream>
#include<vector>
using namespace std;
vector<int>h;  // heights
vector<int>dp;  // dp
int k;
int f(int i){
    if(i>=h.size()){
        return INT16_MAX;  // base case
    }
    if(i==h.size()-1){  // base case
        return 0;
    }
    if(dp[i]!=-1) return dp[i]; // it means dp[i] is already computed
    int ans = INT16_MAX;
    for(int j=1;j<=k;j++){
        if(i+j>=h.size()) break;  // out of array
        ans=min(ans,abs(h[i]-h[i+j])+f(i+j));  // cost we are computing to go from 1 to n
    }
    return dp[i]=ans; // ans
}
int main(){
    int n;
    cin>>n>>k;
    h.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<f(0)<<"\n";
    return 0;
}