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
#include <bits/stdc++.h>
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
const int INF = 1e9 + 5;
#define mod 1000000007
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t1 = INF, t2 = INF;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (t1 > t2) swap(t1, t2);

        if (arr[i] <= t1) {
            t1 = arr[i];
        }
        else if (arr[i] <= t2) {
            t2 = arr[i];
        }
        else {
            t1 = arr[i];
            ans++;
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
