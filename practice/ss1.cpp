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

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int max_diff = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - i - 1]) {
            max_diff = max(max_diff, abs(arr[i] - arr[n - i - 1]));
        }
    }

    if (max_diff == 0) {
        cout << 0 << endl; // All elements are the same or it's already a palindrome
    } else {
        cout << max_diff << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
