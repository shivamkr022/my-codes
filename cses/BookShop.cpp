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
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    for(int i=0;i<n;i++) cin>>price[i];
    vector<int>page(n);
    for(int i=0;i<n;i++) cin>>page[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            dp[i+1][j]= dp[i][j]; // 
            if(j>=price[i]){
                dp[i+1][j] = max (dp[i+1][j], ( page[i] + dp[i][j-price[i]]) );
            }
        }
    }
    cout<<dp[n][x]<<endl;
}