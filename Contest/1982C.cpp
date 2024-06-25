
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

    int n,l,r;
    cin >>n>>l>>r; 
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = 0;     // to store the ans
    int csum = 0;    // current sum
    int start = 0;

        for (int end = 0; end < n; ++end) {
            csum += arr[end];

            while (csum > r && start <= end) {
                csum -= arr[start++];
            }

            if (csum >= l && csum <= r) {
                ans++;
                csum = 0;
                start = end + 1;
            }
        }
        cout <<ans<< endl;
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

