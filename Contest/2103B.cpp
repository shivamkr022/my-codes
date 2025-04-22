#include<bits/stdc++.h>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int count =0;
    int a =0;
    int b =0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            count++;
        }
        else if(s[i]==s[i-1] and s[i]=='1'){
            a++;
        }
        else if(s[i]==s[i-1] and s[i]=='0'){
            b++;
        }
    }
    if(a==n-1){
        cout<<n<<endl;
        return;
    }
    if(a==n-1){
        cout<<n+1<<endl;
        return;
    }
    if(s[0]==0){
    cout<<2*count+a+b<<endl;
    }
    else {
        cout<<2*count+a+b<<endl;
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

