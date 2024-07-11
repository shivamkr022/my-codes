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

bool cross(int n, int m, int k, const string &a) {   // fn to check it can cross road or not
    
    vector<bool> rch(n + 2, false);
    rch[0] = true;  // starting point is reachable always

    queue<pair<int, int>> qu;
    qu.push({0, 0});  

    while (!qu.empty()) {
        int pos = qu.front().first;
        int dist = qu.front().second;
        qu.pop();
        for (int i = 1; i<= m; i++) {
            int pos1 = pos + i;
            if (pos1 >= n + 1) {
                return true;
            }
            if (pos1 <= n && (a[pos1 - 1] == 'C' || rch[pos1])) {
                continue;
            }
            if (pos1 <= n && a[pos1 - 1] == 'L') {
                rch[pos1] = true;
                qu.push({pos1, dist});
            }
            if (pos1 <= n && a[pos1 - 1] == 'W') {
                if (dist + 1 <= k) {
                    rch[pos1] = true;
                    qu.push({pos1, dist + 1});
                }
            }
            if (pos1 == n + 1) {
                return true;
            }
        }
    }
    return false;
}

/* write core logic here */
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string cat;
    cin >> cat;

    if (cross(n, m, k, cat)) {
        cout << "YES" << endl;
    }
    else{
       cout << "NO" << endl;
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

