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
int minFallingPathSum(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n));
    for(int b=0;b<n;b++){
        dp[0][b] = arr[0][b];    // base case 
    }
   for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int up = dp[i - 1][j];
            int leftDiag = j > 0 ? dp[i - 1][j - 1] : INT_MAX;
            int rightDiag = j < n - 1 ? dp[i - 1][j + 1] : INT_MAX;
            dp[i][j] = arr[i][j] + min({up, leftDiag, rightDiag});
        }
    }
    int res = INT_MAX;
    for (int j = 0; j < n; j++) {
        res = min(res, dp[n - 1][j]);
    }
    return res;
}
/* write core logic here */
void solve(){

    /// just put input here 

    //------------------>>>>>>>>>>
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

