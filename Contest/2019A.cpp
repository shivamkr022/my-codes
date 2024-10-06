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
    for(int i=0;i<n;i++) cin>>arr[i];
    int odd = -1;
    int eve =-1;
  
    for(int i=0;i<n;i++){
        if(i%2==0){
            odd = max(odd, arr[i]);
        }
        else{
            eve = max(eve,arr[i]);
        }
    }
   // debug(eve);
  //  debug(odd);
    if(n%2==0){
        if(eve>=odd){
            cout<<((n/2)+eve)<<endl;
            return ;
        }
        else{
            cout<<((n/2)+odd)<<endl;
            return ;
        }
    }
    else{
        if(odd>=eve){
            cout<<(((n+1)/2)+odd)<<endl;
            return ;
        }
        else{
            if(eve-odd>=2){
                cout<<(((n-1)/2)+eve)<<endl;
                return ;
            }
            else{
                cout<<(((n+1)/2)+odd)<<endl;
                return;
            }
        }
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
    cin>>t;
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

