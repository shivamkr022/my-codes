#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> // Include this header for INT16_MAX
using namespace std;

#define inf INT16_MAX // Remove the semicolon at the end of this line
vector<int>dp;
int f(int n){
    if(n==1) return 0;
    if(n==2 or n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return 1+ min({f(n-1),(n%2==0) ? f(n/2) : inf,(n%3==0) ? f(n/3) : inf});
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1005,-1);
    cout<<f(n);
    return 0;
}
