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
    vector<int> a(n - 1);
    for (int &x : a) {
        cin >> x;
    }
    bool lastIsSum = a.back() == n * (n + 1) / 2;
    for (int i = n - 2; i >= 1; i--) {
        a[i] -= a[i - 1];
    }
    sort(a.begin(), a.end());
    vector<int> freq(n + 1, 0); 
    for (int x : a) {
        if (x >= 1 && x <= n) {
            freq[x] = 1;
        }
    }
    int count = accumulate(freq.begin(), freq.end(), 0);
    if (lastIsSum) count++;
    cout << (count == n - 1 ? "YES" : "NO") << endl;
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

