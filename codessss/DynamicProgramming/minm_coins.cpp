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
int minimumElements(vector<int> &arr, int x){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(x+1));
    
    for(int i=0;i<=x;i++){
        if(i%arr[0]==0){
            dp[0][i] = i/arr[0]; // target kuch bhi ho sakta hai thats why we are iterating 0->x
        }
        else{
            dp[0][i] = 1e9;
        }
      }
      for(int i=1;i<n;i++){
          for(int j=0;j<=x;j++){
              int not_take = dp[i-1][j];
              int take = INT_MAX;
              if(arr[i]<=j) take = 1 + dp[i][j-arr[i]]; // yaha take m (i-1) nahi hoga kyuki ek element ko baar baar le sakte hai 
              dp[i][j] = min(take,not_take);            
          }
      }
      int ans = dp[n-1][x];
      if(ans>=1e9) return -1;
       return ans;
    }
/* write core logic here */
void solve(){
    //------------->>>>>>>>>> INPUT
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

