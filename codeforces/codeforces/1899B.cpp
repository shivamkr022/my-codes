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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = -1;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            int mx1 = -1e18, mn1 = 1e18;
            for (int i = 0; i < n; i += d) {
                int sm = 0;
                for (int j = i; j < i + d; ++j) {
                    sm += a[j];
                }
                mx1 = max(mx1, sm);
                mn1= min(mn1, sm);

            }
            debug(mx1);
            debug(mn1);
            ans = max(ans, mx1 - mn1);
        }
    }
    cout << ans << '\n';
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

