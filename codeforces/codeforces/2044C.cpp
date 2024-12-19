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
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int ans =0;
    int total = 2*m;
    if(m>=a){
        if(b>=m){
            int rem1 = total-(a+m);
            if(rem1>=c){
                cout<<(a+m+c)<<endl;
            }
            else{
                cout<<(a+m+rem1)<<endl;
            }
        }
        else{ // b<m
            int rem2= total-(a+b);
            if(rem2>=c){
                cout<<(a+b+c)<<endl;
            }
            else{
                cout<<(a+b+rem2)<<endl;
            }
        }
    }
    else{///// m<a
        if(b>=m){
            int rem1 = total-(m+m);
            if(rem1>=c){
                cout<<(m+m+c)<<endl;
            }
            else{
                cout<<(m+m+rem1)<<endl;
            }
        }
        else{   /// b<m
            int rem2= total-(m+b);
            if(rem2>=c){
                cout<<(m+b+c)<<endl;
            }
            else{
                cout<<(m+b+rem2)<<endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

