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
// int coinchange(vector<int>&arr,int x){
//     sort(arr.begin(),arr.end());
//     int n = arr.size();
//     vector<vector<int>>dp(n,vector<int>(x+1));
//     for(int i = 0; i <= x; i++){
//         dp[0][i] = (i % arr[0] == 0);
//     }    
//     for(int i = 1; i < n; i++){
//         for(int j = 0; j <= x; j++){
//             int not_pick = dp[i - 1][j];
//             int pick = 0;
//             if(j >= arr[i]) pick = dp[i][j - arr[i]];
//             dp[i][j] = (pick + not_pick) % mod;
//         }
//     }    
//     return dp[n-1][x];
// }
int coinchange_space_optimised(vector<int>&arr,int x){
    int n = arr.size();
   vector<int>prev(x+1,0),curr(x+1,0);  // optimised code // space optimised
    for(int i = 0; i <= x; i++){
        prev[i] = (i % arr[0] == 0);
    }    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            int not_pick =prev[j];
            int pick = 0;
            if(j >= arr[i]) pick = curr[j - arr[i]];
            curr[j] = (pick + not_pick) % mod;
        }
        prev = curr;
    }    
    return prev[x];
}
/* write core logic here */
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
   // cout<<coinchange(arr,x)<<endl;
    cout<<coinchange_space_optimised(arr,x)<<endl;

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

