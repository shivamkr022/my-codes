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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int m1=3*a/10;
    int v1=3*b/10;
    int m2=(a-((a/250)*c));
    int v2=(b-((b/250)*d));
    //if(a==b and c==d) cout<<"Tie"<<endl;
    int mcost=max(m1,m2);
    int vcost=max(v1,v2);
    if(mcost==vcost) cout<<"Tie"<<endl;
    else if(mcost>vcost) cout<<"Misha"<<endl;
    else cout<<"Vasya"<<endl;

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