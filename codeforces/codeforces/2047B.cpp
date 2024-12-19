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
bool cmp(pair<char,int> p1, pair<char,int>p2){
    return p1.second<p2.second;
}

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char, int> freq; // To store the frequency of each character

    // Step 1: Count frequencies of all characters
    for (char ch : s) {
        freq[ch]++;
    }

    // Step 2: Find the maximum and minimum frequency characters
    char maxChar = '\0', minChar = '\0';
    int maxFreq = 0, minFreq = INT_MAX;

    for (auto& entry : freq) {
        char ch = entry.first;
        int count = entry.second;

        if (count > maxFreq) {
            maxFreq = count;
            maxChar = ch;
        }

        if (count < minFreq) {
            minFreq = count;
            minChar = ch;
        }
    }

    // Step 3: If max and min frequency characters are the same, replace one occurrence
    bool replaced = false;
    if (maxFreq == minFreq) {
        // Replace the first occurrence of either minChar or maxChar
        for (char& ch : s) {
            if (!replaced && ch == minChar) {
                ch = maxChar;  // Replace first occurrence of minChar with maxChar
                replaced = true;
                break;  // Replace once
            }
        }
    } else {
        // Replace the first occurrence of the min frequency character with max frequency character
        for (char& ch : s) {
            if (!replaced && ch == minChar) {
                ch = maxChar;  // Replace first occurrence of minChar with maxChar
                replaced = true;
                break;  // Replace once
            }
        }
    }
    cout << s << endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

