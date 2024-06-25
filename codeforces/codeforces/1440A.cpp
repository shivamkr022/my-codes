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

    int n,c1,c2,h;
    cin>>n>>c1>>c2>>h;   /// input
    string s;
    cin>>s;

    int x = 0;
    int y = 0;
    for(int i=0;i<s.size();i++){
     if(s[i]=='0') x++;          // counting one and two
     else y++;
    }

    int cost = c1*x + c2*y;   // normal cost

    if(c1==c2) cout<<cost<<endl;
    else if(c1>c2){
        if(c2+h<=c1){                         // just condn aq to ques
           cout<<(x*(c2+h)+y*c2)<<endl;
        }
        else{
            cout<<cost<<endl;
        }
    }
    else if(c2>c1){
        if(c1+h<=c2){                       // just condn aq to ques
           cout<<(y*(c1+h)+x*c1)<<endl;
        }
        else{
            cout<<cost<<endl;
        }
    }
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