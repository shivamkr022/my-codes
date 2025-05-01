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

// int n;
// vector<int>arr;                     recursive solution
// int f(int idx ,int sum1,int sum2){
//     if(idx==n){
//         return abs(sum1-sum2);
//     }
//     return min(
//         f(idx + 1, sum1 + arr[idx], sum2),
//         f(idx + 1, sum1, sum2 + arr[idx])
//     );
    int minSubsetSumDifference(vector<int>& arr, int n){
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        int k = sum;
        
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    
        // Initialize the base cases
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= k)
            dp[0][arr[0]] = true;
    
        for(int i = 1; i < n; i++){
            for(int tar = 1; tar <= k; tar++){
                bool not_take = dp[i-1][tar];
                bool take = false;
                if(arr[i] <= tar)
                    take = dp[i-1][tar - arr[i]];
                dp[i][tar] = take || not_take;
            }
        }
    
        int ans = INT_MAX;
        for(int i = 0; i <= k/2; i++){
            if(dp[n-1][i]){
                int s1 = i;
                int s2 = k - i;
                ans = min(ans, abs(s1 - s2));
            }
        }
    
        return ans;
    }
/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans1 = minSubsetSumDifference(arr,n);
    cout<<ans1<<endl;
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