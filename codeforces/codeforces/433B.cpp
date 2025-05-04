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

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> brr = arr;
    sort(brr.begin(), brr.end());

    vector<int> s(n);
    s[0] = brr[0];
    for (int i = 1; i < n; i++) {
        s[i] = brr[i] + s[i - 1];
    }

    vector<int> sn(n);
    sn[0] = arr[0];
    for (int i = 1; i < n; i++) {
        sn[i] = arr[i] + sn[i - 1];
    }

    int m;
    cin>>m;
    while(m--){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==2){
            if(l-2>=0){
            int ans = abs(s[l-2]-s[r-1]);
            cout<<ans<<endl;
            }
            else{
                cout<<s[r-1]<<endl;
            }
        }
        else{
            if(l-2>=0){
            int ans = abs(sn[l-2]-sn[r-1]);
            cout<<ans<<endl;
            }
            else{
                cout<<sn[r-1]<<endl;
            }
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

