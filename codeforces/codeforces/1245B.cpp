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
    cin>>n;
    int r,p,s;
    cin>>r>>p>>s;
    string str;
    cin>>str;
    int rr = 0, ss = 0, pp = 0;
    for (char c : str) {
        if (c == 'R') rr++;
        else if (c == 'S') ss++;
        else if (c == 'P') pp++;
    }
    int wins = min(r, ss) + min(p, rr) + min(s, pp);
    if (wins < (n + 1) / 2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<char> ans(n, '.'); // Placeholder for the final result
    for (int i = 0; i < n; i++) {
        if (str[i] == 'S' && r > 0) { // Rock beats Scissors
            ans[i] = 'R';
            r--;
        }
        else if (str[i] == 'R' && p > 0) { // Paper beats Rock
            ans[i] = 'P';
            p--;
        }
        else if (str[i] == 'P' && s > 0) { // Scissors beat Paper
            ans[i] = 'S';
            s--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == '.') {
            if (r > 0) {
                ans[i] = 'R';
                r--;
            }
            else if (p > 0) {
                ans[i] = 'P';
                p--;
            }
            else if (s > 0) {
                ans[i] = 'S';
                s--;
            }
        }
    }
    for (char c : ans) cout << c;
    cout << endl;
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

