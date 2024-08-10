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
    int x;
   cin >> x;
    vector<int> ans(31, 0);
    for (int i = 0; i < 30; i++) {
        if (1 & (x >> i)) {
            if (ans[i]) {
                ans[i + 1] = 1;
                ans[i] = 0;
            } 
            else if (i > 0) {
                if (ans[i - 1] == 1) {
                    ans[i + 1] = 1;
                    ans[i - 1] = -1;
                } else {
                    ans[i] = 1;
                }
            }
            else if (i == 0) {
                ans[i] = 1;
            }
        }
    }
    cout << 31 << endl;
    for (int i = 0; i <= 30; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;;

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

