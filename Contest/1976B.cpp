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
    vector<int>a(n);
    vector<int>b(n+1);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n+1;i++){
        cin>>b[i];
    }
    int x= b[n];
    int ans =0;
    int ans1=INT16_MAX;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
    }

    for(int i=0;i<n;i++){
        if(a[i]>x){
            ans1=0;
            break;
        }
        else{
            ans1 = min(ans1,abs(x-a[i]));
        }
    }
    int ans2=ans1+1;
    cout<<ans+ans2<<endl;
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

