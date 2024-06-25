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
int f(vector<int>&v,int n){
    unordered_map<int,int>mp;
    int ans=0; // count no of subarrays 
    int currsum=0;   // currsum
    for(int i=0;i<v.size();i++){
        currsum+=v[i]; // currsum

        if(currsum%n==0){
         ans++;  // one subarray found
        }
        int rem = ((currsum % n) + n) % n; // Handling negative modulo
        if(mp.find(rem)!=mp.end()) {  // it means other subarray found
        ans+=mp[rem];     // (currsum-tar) ka freq hai usko add karenge 
        }
        mp[rem]++;            // and finally usko  aage badha do
    }
    return ans;
}

/* write core logic here */
void solve(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << f(v, n)<<endl;
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