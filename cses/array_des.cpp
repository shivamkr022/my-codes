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

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); 
    if (arr[0] == 0) {
        for (int val = 1; val <= m; val++) {
            dp[0][val] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int val = 1; val <= m; val++) {
                dp[i][val] = ((long long)dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % mod;
            }
        } else {
            int val = arr[i];
            dp[i][val] = ((long long)dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % mod;
        }
    }
    int result = 0;
    for (int val = 1; val <= m; val++) {
        result = (result + dp[n - 1][val]) % mod;
    }
    cout << result << endl;
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

