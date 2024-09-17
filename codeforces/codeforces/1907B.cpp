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

   string s;
   cin >> s;
   int n = s.size();
    vector<int> upper, lower;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                s[i] = '\0';
                if (!lower.empty()) {
                    s[lower.back()] = '\0';
                    lower.pop_back();
                }
                continue;
            }
            if (s[i] == 'B') {
                s[i] = '\0';
                if (!upper.empty()) {
                    s[upper.back()] = '\0';
                    upper.pop_back();
                }
                continue;
            }
            if (s[i] >= 'a' && s[i] <= 'z') {
                lower.push_back(i);
            } else {
                upper.push_back(i);
            }
        }
        
        for (char c : s) {
            if (c != '\0') cout << c;
        }
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

