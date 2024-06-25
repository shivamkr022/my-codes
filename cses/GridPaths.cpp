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
#define mod 1000000007
using namespace std;
vector<vector<char>>grid;
vector<vector<int>>dp;
int n;
int f(int i ,int j){
    if(i==n-1 and j== n-1) return 1;  // base case
    if( i>=n or j>=n ) return 0;  // base case
    if(grid[i][j]=='*') return 0;  // base case
    if(dp[i][j]!=-1) return dp[i][j];  
    return dp[i][j] = (f(i,j+1)+f(i+1,j))%mod;  // reccursive relation
    }
int main(){
cin>>n;
grid.resize(n, vector<char>(n));
dp.clear();
dp.resize(1005,vector<int>(1005,-1));  //dp

for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];        // input of 2d vector
        
        }
    }
if(grid[0][0]=='*' or grid[n-1][n-1]=='*'){  // corner case // like if we cant initialise or end then no of ways iss zero
    cout<<0<<endl;
   return 0; // important
}
cout<<f(0,0)<<endl;  // ans
return 0;
}