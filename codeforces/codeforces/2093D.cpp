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

int fx(vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int mex = 0;
    while (s.count(mex)) mex++;
    return mex;
}

bool is_possible(vector<int>& a, int k, int x) {
    if (x == 0) return true;
    set<int> required;
    for (int i = 0; i < x; i++) required.insert(i);
    int count = 0;
    set<int> current;
    for (int num : a) {
        if (num < x) current.insert(num);
        if (current.size() == required.size()) {
            count++;
            current.clear();
            if (count >= k) return true;
        }
    }
    return count >= k;
}

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int total_mex = fx(arr);
    if (k == 1) return total_mex;
    int low = 0, high = total_mex;
    int answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_possible(arr, k, mid)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return answer;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}