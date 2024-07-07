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
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    for(int i=0;i<n;i++) cin>>price[i];
    vector<int>page(n);
    for(int i=0;i<n;i++) cin>>page[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            dp[i+1][j]= dp[i][j];
            if(j>=price[i]){
                dp[i+1][j] = max (dp[i+1][j], (page[i]+dp[i][j-price[i]]));
               // debug(dp[i+1][j]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
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

