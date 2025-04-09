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
int uniquePaths(int n, vector<vector<char>>& grid) {
  vector<vector<int>> dp(n, vector<int>(n, 0));
  if (grid[0][0] == '*' || grid[n-1][n-1] == '*') return 0;
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '*') {
              dp[i][j] = 0;
              continue;
          }
          if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
          if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
      }
  }
  return dp[n-1][n-1];
}
/* write core logic here */
void solve(){
  int n;
  cin >> n;
  vector<vector<char>> arr(n, vector<char>(n));
  for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
          cin >> arr[i][j];

  cout << uniquePaths(n, arr) << endl;
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

