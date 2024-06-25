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
    int i,j,k;
    string s;
    bool flag =true;
    cin>>s;
    int n= s.length();
    for(int i=0;i<n;){
        if(s[i]=='1' and s[i+1]=='4' and s[i+2]=='4'){ // 144
            i=i+3;
        }
        else if(s[i]=='1' and s[i+1]=='4'){ // 14
            i=i+2;
        }
        else if(s[i]=='1'){ // 1
            i++;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
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