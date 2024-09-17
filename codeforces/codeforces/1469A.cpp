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
    string str;
    cin>>str;
    int n = str.length();
    if(n%2==1){
        cout<<"NO"<<endl;
        return;
    }
    if(str[0]==')' or str[n-1]=='('){
        cout<<"NO"<<endl;
        return;
    }
    int lt =0;
    int rt =0;
    int q =0;
    for(int i=0;i<n;i++){
        if(str[i]==')'){
            lt++;
        }
        else if(str[i]=='('){
            rt++;
        }
        else{
            q++;
        }
    }
    // if(lt==rt and q%2==1){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    cout<<"YES"<<endl;
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

