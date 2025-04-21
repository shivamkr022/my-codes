#include<bits/stdc++.h>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans;
    stack<int> st;
    int num = 1;

    for (int i = 0; i < n - 1; i++) {
        st.push(num++);
        if (s[i] == '>') {
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }
    }
    st.push(num);  // Push the last number
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
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

