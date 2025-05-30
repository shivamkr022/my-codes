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

class Solution {
public:
    // Topological sort using Kahn's Algorithm
    vector<int> topoSort(int n, vector<vector<int>>& adj) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto v : adj[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return topo;
    }

    string findOrder(vector<string>& s) {
        int n = s.size();
        vector<vector<int>> adj(26);            // a-z
        vector<bool> used(26, false);           // track used letters

        // Mark used characters
        for (auto& word : s) {
            for (char c : word) {
                used[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < n - 1; i++) {
            string& s1 = s[i];
            string& s2 = s[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }
            // Invalid case: "abc" before "ab"
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> topo = topoSort(26, adj);
        string ans = "";
        for (int ele : topo) {
            if (used[ele]) {
                ans += (char)(ele + 'a');
            }
        }

        // Extra validation: Check if all used characters are in result
        int usedCount = count(used.begin(), used.end(), true);
        if (ans.size() != usedCount) return "";  // Cycle or disconnected

        return ans;
    }
};

/* write core logic here */
void solve(){
    
    // ---->>> INPUTTT
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

