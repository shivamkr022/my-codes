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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
      cnt[a[i]] += 1;
    }
    int low = 0, high = 2 * (m + n + 10);
    while (low < high) {
      int mid = (low + high) >> 1;
      long long extra = 0;
      long long need = 0;
      for (int i = 0; i < n; i++) {
        if (cnt[i] <= mid) {
          extra += (mid - cnt[i]) / 2;
        }
        else {
          need += cnt[i] - mid;
        }
      }
      if (extra >= need) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << low << endl;
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

