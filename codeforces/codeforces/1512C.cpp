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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    
    int n = s.length();
    int z = count(s.begin(), s.end(), '0');
    int o = count(s.begin(), s.end(), '1');
    int q = count(s.begin(), s.end(), '?');
    
    if (z > a || o > b) {
        cout << -1 << endl;
        return;
    }
    
    // First pass to resolve definite pairs
    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (s[i] == '?' && s[j] != '?') {
            s[i] = s[j];
        } else if (s[i] != '?' && s[j] == '?') {
            s[j] = s[i];
        }
    }
    
    // Update counts after first pass
    z = count(s.begin(), s.end(), '0');
    o = count(s.begin(), s.end(), '1');
    
    // Second pass to resolve remaining '?'
    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (s[i] == '?' && s[j] == '?') {
            if (z + 2 <= a) {
                s[i] = s[j] = '0';
                z += 2;
            } else if (o + 2 <= b) {
                s[i] = s[j] = '1';
                o += 2;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    // Handle middle character for odd length strings
    if (n % 2 == 1) {
        int mid = n / 2;
        if (s[mid] == '?') {
            if (z < a) {
                s[mid] = '0';
            } else if (o < b) {
                s[mid] = '1';
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    // Final palindrome check and count validation
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (s == rev && count(s.begin(), s.end(), '0') == a && count(s.begin(), s.end(), '1') == b) {
        cout << s << endl;
    } else {
        cout << -1 << endl;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}
