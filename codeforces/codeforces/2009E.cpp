#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Read n
        vector<pair<int, int>> nums(n); // Vector to store pairs
        unordered_map<int, int> b; // Map to count occurrences of x
        set<pair<int, int>> check; // Set to check presence of pairs
        
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y; // Read each pair
            nums[i] = {x, y}; // Store the pair in nums
            b[x]++; // Count occurrences of x
            check.insert({x, y}); // Insert the pair into the set
        }
        
        int ans = 0;
        
        // First loop: Check for pairs where b[i] == 2
        for (const auto& entry : b) {
            if (entry.second == 2) {
                ans += n - 2;
            }
        }
        
        // Second loop: Check for conditions with (x-1, y^1) and (x+1, y^1)
        for (const auto& p : check) {
            if (check.count({p.first - 1, p.second ^ 1}) && check.count({p.first + 1, p.second ^ 1})) {
                ans++;
            }
        }
        
        // Print the result
        cout << ans << endl;
    }
    
    return 0;
}
