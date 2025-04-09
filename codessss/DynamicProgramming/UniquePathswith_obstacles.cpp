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

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
int uniquePaths(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n));
    dp[0][0]=1;   // base case
    if(obstacleGrid[m-1][n-1]!=0){
        return 0;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if (i == 0 && j == 0) continue; // <-- Important!
            int up=0;
            int dd=0;
            if(i>0 and obstacleGrid[i-1][j]==0) up = dp[i-1][j];
            if(j>0 and obstacleGrid[i][j-1]==0) dd = dp[i][j-1];
            dp[i][j] = up+dd;
        }
    } 
    return dp[m-1][n-1];
}
/* write core logic here */
void solve(){
    vector<vector<int>> arr;
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<uniquePaths(arr)<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

