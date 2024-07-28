#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        long long count = 0;

        // Iterate over possible values of a
        for (int a = 1; a <= x; ++a) {
            // Iterate over possible values of b
            for (int b = 1; b <= x - a; ++b) {
                // Calculate the maximum possible value of c
                int max_c = x - a - b;
                
                if (a + b > 0) {
                    int max_c_by_n = (n - a * b) / (a + b);
                    if (max_c_by_n >= 0) {
                        int valid_c = min(max_c, max_c_by_n);
                        if (valid_c >= 1) {
                            count += valid_c;
                        }
                    }
                }
            }
        }

        cout << count << endl;
    }
    
    return 0;
}
