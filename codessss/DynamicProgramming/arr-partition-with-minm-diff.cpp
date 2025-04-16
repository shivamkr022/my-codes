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
int minSubsetSumDifference(vector<int>& arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int k = sum;
   vector<vector<bool>>dp(n,vector<bool>(k+1,0));

   for(int i=0;i<n;i++)dp[i][0] = true;
   if(arr[0]<=k) dp[0][arr[0]] = true;

   for(int i=1;i<n;i++){
    for(int tar=1;tar<=k;tar++){
        bool not_take = dp[i-1][tar];
        bool take = false;
        if(arr[i]<=tar) take = dp[i-1][tar-arr[i]];
        dp[i][tar] = take | not_take ;
     }
   }
    int ans = INT_MAX;
    for(int i=0;i<=k/2;i++){   
       if (dp[n-1][i]==true){  // n-1 th row m pura dp store hai 
       // it means ki ith sum present hai n-1 th column m 
        int s1 =i;  // first subset
        int s2 = k-i;  // second subset
        int diff = abs(s1-s2);  // absolute diff
        ans = min(ans,diff);   // answer
       }
    }
    return ans;
    }

/* write core logic here */
void solve(){
    ////////////
 //   -------->>>>>input----->>>>>>
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

