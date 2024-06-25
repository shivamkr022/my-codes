#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int f(int n){
    if(n==0 or n==1)return n;
    // dp check // like we computed the value or not
    return dp[n]= f(n-1)+f(n-2);
}
int main(){
    int n;
    cin>>n;
    dp.clear();  // remove if garbage value is present
    dp.resize(n+1,-1);  // initiate vector wih -1
    cout<<f(n)<<"\n";
}