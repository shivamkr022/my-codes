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
using namespace std;         /// this is DP with bit-mask
bool canPartitionKSubsets(vector<int>& arr, int k) {
    int n = arr.size();
    int sum =0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum % k!=0) return false;
    int tar = sum/k; /// wrong solution
    vector<vector<int>>dp(n,vector<int>(tar+1));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    if(arr[0]<=tar) dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j =0;j<=tar;j++){
            int not_take = dp[i-1][j];
            int take = false;
            if(arr[i]<=j) take = dp[i-1][j-arr[i]];
            dp[i][j] = take +not_take;
        }
    }
    if(dp[n-1][tar]==k) return true;
    else return false;
}
/* write core logic here */
void solve(){
    int k,n;
    cin>>k>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<canPartitionKSubsets(arr,k) <<endl;
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

