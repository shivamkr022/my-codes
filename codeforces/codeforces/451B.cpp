/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam            |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < (int)v.size(); i++) { \
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
using namespace std;

/* core logic */
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = -1, r = -1;

    // find left index where array first decreases
    for(int i = 0; i + 1 < n; i++){
        if(a[i] > a[i+1]){
            l = i;
            break;
        }
    }

    // already sorted
    if(l == -1){
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }

    // find right index where array last decreases
    for(int i = n - 1; i - 1 >= 0; i--){
        if(a[i-1] > a[i]){
            r = i;
            break;
        }
    }

    debug(l);
    debug(r);

    vector<int> b = a;
    reverse(b.begin() + l, b.begin() + r + 1);

    // check if sorted
    bool sorted = true;
    for(int i = 0; i + 1 < n; i++){
        if(b[i] > b[i+1]){
            sorted = false;
            break;
        }
    }

    if(sorted){
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }
    else{
        cout << "no" << endl;
    }
}

/* main */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}
