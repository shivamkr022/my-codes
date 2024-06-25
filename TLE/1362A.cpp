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

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    
    if (b % a != 0) {
        cout << -1 << endl;
        return;
    }

    int k = b / a;
    int steps = 0;
    
    while (k % 8 == 0) {
        k /= 8;
        steps++;
    }
    while (k % 4 == 0) {
        k /= 4;
        steps++;
    }
    while (k % 2 == 0) {
        k /= 2;
        steps++;
    }

    if (k == 1) {
        cout << steps << endl;
    } 
    else {
        cout << -1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
