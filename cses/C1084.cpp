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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>app(n);
    vector<int>flat(m);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>app[i];   // appartments
    }
        for(int i=0;i<m;i++){
        cin>>flat[i];    // flats
    }
    sort(app.begin(),app.end());  // sorting
    sort(flat.begin(),flat.end());
    int i=0;  // applicant
    int j=0;   // flat
    while(i<n){
        while(j<m && app[i]-k>flat[j]) j++;  // that customer cant get the flat
        if(abs(app[i]-flat[j])<=k){    // got the flat
            ans++;
            i++;
            j++;
        }
        else i++; 
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