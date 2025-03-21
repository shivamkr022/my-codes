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
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int equal[n+1]={0};
    int zc=0;
    int oc =0;
    int i;
    for(i=0;i<n;i++){
        if(a[i]=='1')
        oc++;
        else 
        zc++;
        if(oc==zc)
        equal[i]=1;
    }
    bool f= true;
    int flipped = 0;
    for(i=n-1;i>=0;i--){
        if(flipped ==0 && a[i]!=b[i]){
        if(equal[i]==0)
        f=false;
        else 
        flipped = 1;
        }
        if(flipped==1 && a[i]==b[i]){
            if(equal[i]==0)
            f=false;
            else 
            flipped = 0;
        }
    }
    if(f)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
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

