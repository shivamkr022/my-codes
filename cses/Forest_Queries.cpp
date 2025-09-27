/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam             |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

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
    int n,q;
    cin>>n>>q;
    vector<vector<int>> pref(n+1, vector<int>(n+1,0));

    // build prefix sum
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            int val = (c == '*'); // 1 if tree, else 0
            pref[i][j] = val + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }

    // answer queries
    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        int ans = pref[y2][x2] - pref[y1-1][x2] - pref[y2][x1-1] + pref[y1-1][x1-1];
        cout << ans << endl;
    }
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
