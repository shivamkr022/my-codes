#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    
    int res;
    std::cout << "mul 9" << std::endl;
    std::cin >> res;
    assert(res == 1);
    
    std::cout << "digit" << std::endl;
    std::cin >> res;
    assert(res == 1);
    
    std::cout << "digit" << std::endl;
    std::cin >> res;
    assert(res == 1);
    
    std::cout << "add " << n - 9 << std::endl;
    std::cin >> res;
    assert(res == 1);
    
    std::cout << "!" << std::endl;
    std::cin >> res;
    assert(res == 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}