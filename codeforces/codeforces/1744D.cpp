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
    cin >> n;
    int eve = 0;
    vector<int> lol;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x % 2 == 0) {
            eve++;
            x /= 2;
        }
    }
    if (eve >= n) { 
        cout << 0 << endl; 
        return; 
    }
    int rem = n - eve;
    for (int i = 1; i <= n; i++) { 
        int val = 0, temp = i;
        while (temp % 2 == 0) {
            val++;
            temp /= 2;
        }
        lol.push_back(val);
    }
    sort(lol.rbegin(), lol.rend()); 
    int y = 0;
    for (int i = 0; i < lol.size(); i++) {
        if (rem > lol[i]) {
            rem -= lol[i];
            y++;
        }
        else { 
            cout << y + 1 << endl;
            return;
        }
    }
    cout << -1 << endl; 
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

