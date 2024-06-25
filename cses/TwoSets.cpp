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
typedef long long ll;

/* write core logic here */
void solve(){
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2!=0){
        cout<<"NO"<<endl;  // it cant be part in two equal sum
    }
    else{ // can be done in two equal sum
        cout<<"YES"<<endl;
        set<ll>s1,s2; // sets
        ll tar = sum/2;
        int t =n;
        for(int i=1;i<=n;i++)
        s1.insert(i);  // put all ele in set1
        while(s1.count(tar)==0){
            tar-=t;  // subtract
            s2.insert(t);
            s1.erase(t);
            t--;
        }
        s1.erase(tar);
        s2.insert(tar);
        cout<<s1.size()<<"\n";

        for(int z : s1)
            cout<< z<<" ";
        
        cout<<s2.size()<<"\n";
        for(int z : s2)
            cout<< z<<" ";
    }
}
/* logic ends */

signed main(){
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

