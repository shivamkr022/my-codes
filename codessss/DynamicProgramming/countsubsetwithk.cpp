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
int findWays(vector<int>& a, int k){
    int n = a.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    if (a[0] == 0) {
        dp[0][0] = 2; // Include and exclude 0  // due to 0 else 1
    }
    else {
        dp[0][0] = 1;
        if (a[0] <= k) dp[0][a[0]] = 1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int no_take = dp[i-1][j];
            int take  = 0;
            if(a[i]<=j) take = dp[i-1][j-a[i]];
            dp[i][j] = (take + no_take) % mod;
        }
    }
    return dp[n-1][k];
}
/* write core logic here */
void solve(){
    //--------->>>>input______>>>>>>>>>
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

