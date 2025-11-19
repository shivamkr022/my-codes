#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    string s; cin >> s;
    int n = s.size();
    
    for (int i = 0; i + 1 < n; i++){
        if (s[i] == '*' && s[i + 1] == '*'){
            cout << -1 << "\n";
            return;
        }
    }
    
    for (int i = 0; i + 1 < n; i++){
        if (s[i] == '>' && s[i + 1] == '<'){
            cout << -1 << "\n";
            return;
        }
        if (s[i] == '>' && s[i + 1] == '*'){
            cout << -1 << "\n";
            return;
        }
        if (s[i] == '*' && s[i + 1] == '<'){
            cout << -1 << "\n";
            return;
        }
    }
    
    int p = 0;
    while (p < n && s[p] == '<'){
        p++;
    }
    
    if (p == n){
        cout << n << "\n";
        return;
    }
    int ans;
    if (s[p] == '*') ans = max(p + 1, n - p);
    else ans = max(p, n - p);
    cout << ans << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}