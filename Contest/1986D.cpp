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
    string s;
    cin>>s;
    string tt = "";
    tt+=s[0];
    tt+=s[1];
   bool flag = false;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
       flag=true;
            break;
        }
    }
    if(flag==true){
        cout<<0<<endl;
    }
    else{
    for(int i=1;i<n-1;i++){
        string curr="";
        curr+=s[i];
        curr+=s[i+1];
        if(tt>curr){
            tt=curr;
        }
    }

    size_t pos;
    while ((pos = s.find(tt)) != std::string::npos) {
        s.erase(pos, tt.length());
    }

 int num1 = stoi(s);
 int num2 = stoi(tt);
     int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            if((c - '0')!=1)
            sum += c - '0';
        }
    }
    cout<<sum+num2<<endl;
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

