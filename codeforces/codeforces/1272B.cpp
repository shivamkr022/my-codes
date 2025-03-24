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
    string s;
    cin>>s;
    int d = count(s.begin(),s.end(),'D');
    int u = count(s.begin(),s.end(),'U');
    int l = count(s.begin(),s.end(),'L');
    int r = count(s.begin(),s.end(),'R');
    int lr = min(l,r);
    int ud = min(u,d);
    if(r==0 or l==0){
        if(d>0 and u>0 ){
            cout<<2<<endl;
            cout<<"UD"<<endl;
            return;
        }
        else{
            cout<<0<<endl;
            return;
        }
    }
    if(d==0 or u==0){
        if(l>0 and r>0){
            cout<<2<<endl;
            cout<<"RL"<<endl;
            return;
        }
        else{
            cout<<0<<endl;
            return;
        }
    }
    string s1=string(lr,'L');
    string s2=string(lr,'R');
    string s3=string(ud,'U');
    string s4=string(ud,'D');
    int ans =2*(lr+ud);
    if(ans!=0){
        cout<<ans<<endl;
    cout<<(s3+s2+s4+s1)<<endl;
    }
    else{
        cout<<0<<endl;
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

