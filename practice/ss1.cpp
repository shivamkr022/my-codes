#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> all_elements;
        
        // Read matrix a
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                all_elements.push_back(a[i][j]);
            }
        }
        
        // Sort all elements
        sort(all_elements.begin(), all_elements.end());
        
        // Create matrix b
        vector<vector<int>> b(n, vector<int>(m));
        
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[i][j] = all_elements[(index + 1) % (n * m)];
                index++;
            }
        }
        
        // Check if matrix b is valid
        bool valid = true;
        for (int i = 0; i < n && valid; ++i) {
            for (int j = 0; j < m && valid; ++j) {
                if (a[i][j] == b[i][j]) {
                    valid = false;
                }
            }
        }
        
        // Output result
        if (valid) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
