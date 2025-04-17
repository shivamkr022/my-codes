#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

ll knapsack_tabulation(vector<int>& wts, vector<int>& val, int n, int W) {
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int w = 0; w <= W; w++) {
            ll not_take = dp[idx + 1][w];
            ll take = 0;
            if (wts[idx] <= w) {
                take = val[idx] + dp[idx + 1][w - wts[idx]];
            }
            dp[idx][w] = max(take, not_take);
        }
    }

    return dp[0][W];
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> wts(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> wts[i] >> val[i];
    }

    cout << knapsack_tabulation(wts, val, n, w) << endl;
    return 0;
}
