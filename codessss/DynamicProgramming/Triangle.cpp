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
int minimumTotal(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n));
    for(int b=0;b<n;b++){
        dp[n-1][b] = arr[n-1][b];    // base case 
    }
    for(int i=n-2;i>=0;i--){   // loop is nothing scary its just according to the given triangle
        for(int j=i;j>=0;j--){
            dp[i][j] = min(arr[i][j]+dp[i+1][j],arr[i][j]+dp[i+1][j+1]);  // as usual we know very welll
       }
    }
    return dp[0][0];
}
/* write core logic here */
void solve(){
    //// just put input of given triangle
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

