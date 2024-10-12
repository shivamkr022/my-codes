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
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int one =0;
    int two=0;
    int three=0;
    int ff =0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) one++;
        if(arr[i]==2) two++;
        if(arr[i]==3) three++;
        if(arr[i]==4) ff++;
    }
    int tt= two/2;
    int  rtt = two%2;
    int tro=0;  // couple one and three makes
    int ro=0;   // rem ones
    int rt=0;   // rem threes
    int ott =0;  // cal one and two couples
    int frem =0;
    if(one=three){
        tro = three;
    }
    else if(one>three){
        tro=three;
        ro=one - three;
    }
    else{
        tro=one;
        rt = three-one;
    }
    if(rtt=ro){
        ott = ro;
    }
    else if(rtt>ro){
        ott=ro;
        frem=rtt-ro;
    }
    else{
        ott=rtt;
        frem=ro-rtt;
    }
    debug(tt);
    debug(ott);
    int ans = ff+tro+ott+tt+frem;
    cout<<ans<<endl;

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

