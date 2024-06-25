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
    int n,m; // given input
    cin>>n>>m;
    vector<int>input(n); // vector
    for(int i=0;i<n;i++) cin>>input[i];
    sort(input.begin(),input.end()); // sorting 
    int sum1=0;  // to store the sum
    for(int i=0;i<=m-1;i++){
        if(input[i]<0 ){
         sum1+=abs(input[i]); // summation if at least one negative is there in vector
        }
     } 
    cout<<sum1<<endl; // ans
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