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
bool canPartition(vector<int>& a) {
    int n = a.size();
    int sum =0;
    for(int ele :a){
        sum+=ele;
    }
    if(sum%2==1){
        return false;
    }
    int k = sum/2;
vector<vector<bool>>dp(n+1,vector<bool>(k+1));
for(int i=0;i<n;i++){
    dp[i][0]=true;
}
if (a[0] <= k) dp[0][a[0]] = true;
for(int i=1;i<n;i++){
    for(int j=1;j<=k;j++){
        bool no_take = dp[i-1][j];
        bool take  = false;
        if(a[i]<=j) take = dp[i-1][j-a[i]];
        dp[i][j] = take | no_take ;
    }
}
return dp[n-1][k];
}
/* write core logic here */
void solve(){
    ////input
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

