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
    int n,x;
    cin>>n>>x;

    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];  // input
    int sumofarray =0;
    int count =0;
    int sum1=0;

    for(int i=0;i<n;i++){
        sumofarray+=v[i];
        if(v[i]%x!=0){             // solve
            sum1+=((v[i]/x)+1);
        }
        else{
            sum1+=(v[i]/x);
        }
    }

    if(sumofarray%x==0)
    cout<<sumofarray/x<<" "<<sum1<<endl;          // output
    else cout<<((sumofarray/x)+1)<<" "<<sum1<<endl;
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

