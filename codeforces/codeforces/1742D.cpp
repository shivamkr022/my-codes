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
const int N = 1e6;
const int M = N + 7;
const double EPS = 1e-10;
const int MOD = 1e9 + 7; 
int mx[1010];
int n;
int a[M];
/* write core logic here */
void solve(){
    cin >> n;
    for (int i = 0; i <= 1000; i++) mx[i] = 0;
    for (int i = 1; i <= n; i++){
      cin >> a[i];
      mx[a[i]] = max(mx[a[i]], i);
    }
    int ans = -1;
    for (int i = 1; i <= 1000; i++){
      for (int j = i; j <= 1000; j++){
        if (__gcd(i, j) == 1 && min(mx[i], mx[j]) > 0){
          ans = max(ans, mx[i] + mx[j]);
        }
      }
    }
    cout << ans << endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}