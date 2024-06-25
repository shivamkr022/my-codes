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
     if(n%4==0 || n%7==0 || n%44==0|| n%47==0 || n%74==0 ||n%77==0 || n%444==0 || n%447==0 || n%474==0 || n%744==0 || n%477==0 || n%747==0 || n%774==0 || n%777==0 )
    {
        cout<<"YES";
    }
    else
        {
        cout<<"NO";
    }

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