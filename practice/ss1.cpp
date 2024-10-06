#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int operations = 0;
    
    // Process until n becomes 0
    while (n > 0) {
        // If n is not divisible by k, subtract the remainder and count that as an operation
        if (n % k != 0) {
            operations += n % k;  // Each remainder needs separate operations
            n -= n % k;
        } else {
            // If n is divisible by k, just divide n by k
            n /= k;
            operations++;  // Division by k counts as one operation
        }
    }
    
    cout << operations << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // Solve each test case
    while (t--) {
        solve();
    }

    return 0;
}
