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
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    int n;
    cin>>n;
    while(n--){
        int x,y,z;
        cin>>x>>y>>z;
    //    vector<int>v;
        //int ans = x+y+z;
        v1.push_back(x);
        v2.push_back(y);
        v3.push_back(z);
          //  print(v1);
    }

   int sum1 =0;
   int sum2=0;
   int sum3=0;
    for(int i=0;i<v1.size();i++){
        sum1+=v1[i];
    }
    for(int i=0;i<v2.size();i++){
        sum2+=v2[i];
    }
    for(int i=0;i<v3.size();i++){
        sum3+=v3[i];
    }
    if(sum1==0 and sum2==0 and sum3==0){
        cout<<"YES"<<endl;
        return;
    }
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

