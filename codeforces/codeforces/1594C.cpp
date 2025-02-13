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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool all_c = true;
    for (char ch : s) {
        if (ch != c) {
            all_c = false;
            break;
        }
    }
    if (all_c) {
        cout << 0 << endl;
        return;
    }

    for (int x = 1; x <= n; x++) {
        bool valid = true;
        for (int i = x; i <= n; i += x) {
            if (s[i - 1] != c) { 
                valid = false;
                break;
            }
        }
        if (valid){
            cout << 1 << endl << x << endl;
            return;
        }
    }

    cout << 2 << endl;
    cout << n << " " << n - 1 << endl;
    // vector<int>store;
    // for(int i=0;i<n;i++){
    //     if(s[i]!=ch){
    //         store.push_back(i+1);
    //     }
    // }
    // int n1 = store.size();
    // if(n1==0){
    //     cout<<0<<endl;
    //     return;
    // }
    // bool check  = true;
    // for(int i=0;i<n1;i++){
    //     if(store[i]!=ch and (i+1)%2==0){
    //         check=false;
    //         break;
    //     }
    // }
    // // //debug(n1);
    // // print(store);

    // if(s[n-1]!=ch){
    // cout<<2<<endl;
    // cout<<(n-1)<<" "<<(n)<<endl;
    // }

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

