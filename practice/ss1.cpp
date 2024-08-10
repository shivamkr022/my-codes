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
        string s, t;
        cin >> s >> t;
        
        int m = s.size(), n = t.size();
        if (n > m) {
            cout << "NO\n";
            return;
        }

        bool flag = false;
        string original_s = s; 

        for (int i = 0; i <= m - n; i++) {
            s = original_s; 
            int k = 0; 

            for (int j = i; j < m && k < n; j++) {
                if (s[j] == '?' || s[j] == t[k]) {
                    s[j] = t[k];
                    k++;
                }
            }
            for (char &ch : s) {
                if (ch == '?') ch = 'a';
            }

            int t_idx = 0; 
            for (char ch : s) {
                if (t_idx < n && ch == t[t_idx]) {
                    t_idx++;
                }
            }
            if (t_idx == n) { 
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
        else {
            cout<<"NO"<<endl;
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

