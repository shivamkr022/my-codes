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
    int n,k;
    cin>>n>>k;
    if(n%2==0 and n/2>=k){
        int ans1= 2*k-1;
        cout<<ans1<<endl;
    }
    else if(n%2==0 and n/2<k){
        int m=n/2;
        int rem=k-m;
        int ans2=2*rem;
        cout<<ans2<<endl;
    }
    else if(n%2!=0 and ((n/2)+1)>=k){
      
        int ans3=2*k-1;
        cout<<ans3<<endl;
    }
    else{
        int m2=((n/2)+1);
        int rem1=k-m2;
        int ans4=2*rem1;
        cout<<ans4<<endl;
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