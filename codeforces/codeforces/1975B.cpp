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
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   sort(arr.begin(),arr.end());
   int x=arr[0];
   int y=-1;
   for(int i=1;i<n;i++){
    if(arr[i]%x!=0){
        y=arr[i];
        break;
     }
   }

if(x==1 or y==1){
    cout<<"YES"<<endl;
    return;
}
for(int i=0;i<n;i++){
    if(arr[i]%x!=0 and arr[i]%y!=0){
        cout<<"NO"<<endl;
        return;
    }
   }
   cout<<"YES"<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}
