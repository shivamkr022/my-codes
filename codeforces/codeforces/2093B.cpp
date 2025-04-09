#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        ld minCost = 1e18;
        int minRemoved = n - 1;
        for (int mask = 1; mask < (1 << n); ++mask) {
            string numStr = "";
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    numStr += s[i];
                    sum += s[i] - '0';
                }
            }
            if (numStr.empty() || sum == 0) continue;
            ld val = 0;
            for (char ch : numStr)
                val = val * 10 + (ch - '0');
            ld cost = val / sum;
            int removed = n - numStr.size();
            if (cost < minCost || (abs(cost - minCost) < 1e-9 && removed < minRemoved)) {
                minCost = cost;
                minRemoved = removed;
            }
        }
        cout << minRemoved << endl;
    }
    return 0;
}
