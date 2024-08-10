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
    string s,t;
    cin>>s>>t;
    if(t.length()>s.length()){
        cout<<"NO"<<endl;
        return;
    }
    int q=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='?'){
            q++;
        }
    }
    if(q>=t.length()){
        cout<<"YES"<<endl;
        cout<<t<<endl;
        return;
    }
    if(s.length()==t.length()){
        bool flag = true;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i] and s[i]!='?'){
                flag = false;
            }
        }
        if(flag==true){
            cout<<"YES"<<endl;
            cout<<t<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    if(s.length()>t.length()){
        int i=0;
        int j=0;
        while(i<s.length() and j<t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else if(s[i]!=t[j]){
                i++;
            }
            else if(s[i]=='?'){
                s[i]=t[j];
                i++;
                j++;
                q--;
            }
        }
    if(q==0){
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<"NO"<<endl;
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

