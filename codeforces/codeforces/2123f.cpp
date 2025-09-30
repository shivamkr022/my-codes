#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;

        // Sieve primes up to n
        vector<int> mindiv(n+1, 0);
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (mindiv[i] == 0) {
                mindiv[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > mindiv[i] || 1LL * p * i > n) break;
                mindiv[p * i] = p;
            }
        }

        vector<int> res(n+1, 0);
        vector<char> used(n+1, false);

        // 1 must be at position 1 (cannot place 1 at i>=2)
        res[1] = 1;
        used[1] = true;

        // For each prime, collect unassigned multiples and rotate them
        for (int p : primes) {
            vector<int> v;
            for (int k = p; k <= n; k += p) {
                if (!used[k]) {
                    v.push_back(k);
                    used[k] = true; // mark position as handled (it will be assigned a value from v)
                }
            }
            if (v.empty()) continue;
            // rotate assignment inside v: for position v[i] assign value v[(i+1)%v.size()]
            int m = (int)v.size();
            for (int i = 0; i < m; ++i) {
                res[v[i]] = v[(i + 1) % m];
            }
        }

        // Output permutation positions 1..n
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}
