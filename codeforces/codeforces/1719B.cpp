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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>v;
    vector<bool> used(n + 1, false);  // Track used numbers
    for (int i = 1; i < n; i++) {
        if (used[i]) continue;  // Skip already paired numbers
        for (int j = i + 1; j <= n; j++) {
            if (!used[j] && (((i * j) + (j * k)) % 4 == 0)) {  
                v.push_back({i, j});
                used[i] = used[j] = true;  // Mark numbers as used
                break; 
            }
        }
    }
    if (v.empty()) {
        cout <<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for (auto ele : v) {
            cout << ele.first << " " << ele.second << "\n";
        }
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

