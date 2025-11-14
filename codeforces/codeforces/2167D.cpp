/*
  ------------------------------------------
 |                                        |
 |         Code Crafted by Shivam         |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" = "<<x<<endl 
#define print(v) do { \
    cout << "vect--" << #v << " = [ "; \
    for (int i = 0; i < v.size(); i++) cout << v[i] << " "; \
    cout << "]" << endl; \
} while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

bool is_coprime(int a, int b){
    return __gcd(a, b) == 1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int g = a[0];
    for(int i = 1; i < n; i++) g = __gcd(g, a[i]);
    //debug(g);
    if(g == 1){
        cout << 2 << endl;
        return;
    }
    int ans = -1;
    for(int x = 2; x <= 100; x++){ // check small numbers (2..100 enough)
        if(__gcd(g, x) == 1){
            ans = x;
            break;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
