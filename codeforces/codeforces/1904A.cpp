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
    set<pair<int, int>> S1, S2;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    S1.insert({c - a, d - b});
    S1.insert({c + a, d - b});
    S1.insert({c - a, d + b});
    S1.insert({c + a, d + b});
    S1.insert({c - b, d - a});
    S1.insert({c + b, d - a});
    S1.insert({c - b, d + a});
    S1.insert({c + b, d + a});

    // All possible "knight" like moves from (e, f)
    S2.insert({e - a, f - b});
    S2.insert({e + a, f - b});
    S2.insert({e - a, f + b});
    S2.insert({e + a, f + b});
    S2.insert({e - b, f - a});
    S2.insert({e + b, f - a});
    S2.insert({e - b, f + a});
    S2.insert({e + b, f + a});

    // Count common points
    int commonCount = 0;
    for (const auto& p : S1) {
        if (S2.find(p) != S2.end()) {
            commonCount++;
        }
    }

    cout << commonCount << endl;
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

