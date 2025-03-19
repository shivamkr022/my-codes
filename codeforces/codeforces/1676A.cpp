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
int f(int num){
    int sum=0;
    while(num>0){
    sum+=num%10;
    num=num/10;
    }
    return sum;
}
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    string fi = s.substr(0, n / 2);     
    string se = s.substr(n / 2, n / 2); 
    int ff = stoi(fi);
    int ss = stoi(se);
    int d1=f(ff);
    int d2=f(ss);
    if(d1==d2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    // debug(fi);
    // debug(se);
}
int32_t main(){
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