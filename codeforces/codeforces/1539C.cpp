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
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<int> needs;
    int groups = n; 
    for (int i = 1; i < n; i++){
        int diff = a[i] - a[i - 1];
        if (diff > x){
            needs.push_back((diff - 1) / x); 
        }
        else {
            groups--; 
        }
    }
    sort(needs.begin(), needs.end()); 
    for (int t : needs){
        if (k >= t){
            k -= t;
            groups--;
        }
        else{
            break;
        }
    }
    cout << groups << endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

