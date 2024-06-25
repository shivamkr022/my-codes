#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){  // input as vector
        cin>>v[i];
    }
    int sum=0; // total sum
    int rem=0; // sum > half
    int ans=0;  // no of coins
    for(int i=0;i<n;i++){
        sum+=v[i];  // total sum
    }
    int half=sum/2;
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;i--){
       rem+=v[i];
       ans++;
       if(rem>half){ // condition till rem became greater
        break;
       }
    }
    cout<<ans<<endl;
}
int32_t main(){
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