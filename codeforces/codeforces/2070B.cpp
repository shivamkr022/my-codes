/*
**  Compete against Yourself.
**  Author - Shivam kumar
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
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%mod;} else {int u=po(a,b-1);return (a*1LL*u)%mod;}}
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define all(x) (x).begin(),(x).end()
using namespace std;

/* write core logic here */
void solve(){
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int req = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') --x;
        else ++x;
        if (x == 0) {
            req = i + 1;
            break;
        }
    }
    if (req == -1 || req > k) {
        cout << "0" << endl;
        return ;
    }
    k -= req;
    x = 0;
    req = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') --x;
        else ++x;
        if (x == 0) {
            req = i + 1;
            break;
        }
    }
    if (req == -1) {
        cout << "1" << endl;
        return ;
    }
    cout << (k / req + 1) << endl;
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