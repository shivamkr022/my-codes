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

// int lis(vector<int>&arr ,int n){
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     for(int curr=n-1;curr>=0;curr--){//
//         for(int prev =curr-1;prev>=-1;prev--){
//             // not take // just we are going to next index and prev index remains same as we not take ele
//             int len = dp[curr+1][prev+1] ;// prev+1 just for coordinate shif (make -1 -> 0)
//             // take case
//             if(prev==-1 or arr[curr]>arr[prev]){
//                 len = max(len , 1+dp[curr+1][curr+1]); // prev k jagah curr idx swap
//             }
//             dp[curr][prev+1] = len;
//         }
//     }
//     return dp[0][-1+1];
// }


// int lis1(vector<int>&arr ,int n){ /// space optimised
//     vector<int>nxt(n+1,0),crr(n+1,0);
//     for(int curr=n-1;curr>=0;curr--){//
//         for(int prev =curr-1;prev>=-1;prev--){
//             // not take // just we are going to next index and prev index remains same as we not take ele
//             int len = nxt[prev+1] ;// prev+1 just for coordinate shif (make -1 -> 0)
//             // take case
//             if(prev==-1 or arr[curr]>arr[prev]){
//                 len = max(len , 1+nxt[curr+1]); // prev k jagah curr idx swap
//             }
//             crr[prev+1] = len;
//         }
//         nxt=crr;
//     }
//     return nxt[-1+1];
// }


// int lis3(vector<int>&arr ,int n){
//     vector<int>dp(n,1);
//     int ans =1;
//     for(int i=0;i<n;i++){
//         for(int prev=0;prev<i;prev++){
//            if(arr[i]>arr[prev]) dp[i] = max(dp[i],1+dp[prev]);
//         }
//         ans = max(ans,dp[i]);
//     }
//     return ans;
// }
int lis_opt(vector<int>& arr, int n) { // N * log(N) solution
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
        if (it == temp.end()) {
            temp.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    return temp.size();
}

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans  = lis_opt(arr,n);
    cout<<ans<<endl;
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

