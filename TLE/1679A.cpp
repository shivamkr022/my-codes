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
    cin>>n; // input
    int x=0; // count for max
    int y=0; // count for min
    int z=0;
    if(n>=4){
    if((n%4==0 or n%4==2) and (n%6==0) ){
       cout<<n/6<<" "<<n/4<<endl;
    }
    else if((n%4==0 or n%4==2) and (n%6==2 or n%6==4)){ // a/q to que 
      cout<<((n/6)+1)<<" "<<(n/4)<<endl;
    }
    else if(n<4){
        cout<<-1<<endl;
      }
    else{
        cout<<-1<<endl;
    }
    }
    else{
        cout<<-1<<endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

