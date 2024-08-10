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
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bool pos = true;
    bool neg = true;
    
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            pos=false;
        }
        else{
            neg = false;
        }
    }
    if(neg==true){
       int ans1=0;
        for(int i=0;i<n;i++){
            ans1+=arr[i];
        }
        int rans1 = (ans1 % mod + mod) % mod; // Adjusting for negative values
        cout << rans1 << endl;
        return;
    }
    int posans=0;
    if(pos==true){
        int ans2=0;
        while(k!=0){
            for(int i=0;i<arr.size();i++){
                ans2+=arr[i];
            }
            posans=ans2;
            arr.push_back(ans2);
            k--;
        }
        cout<<(posans%mod)<<endl;
        return;
    }
    int curr=0;
    int sum=INT_MIN;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(curr>sum){
            sum=curr;
        }
        if(curr<0){        // kadanes algo for max sum subarray
            curr=0;
        }
    }
    //debug(sum);
    int ksum=0;
    for(int i=0;i<n;i++){
        ksum+=arr[i];
    }
    if(pos==false and neg==false){
            cout<<(ksum%mod+(k*sum)%mod)%mod<<endl;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}