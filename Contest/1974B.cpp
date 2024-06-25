
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int f() {
 int x;
 cin >> x;
 return x;
}

string g() {
 string str;
 cin >> str;
 return str;
}

int main() {
 int t = f();
 while (t--) {
 int n = f();
 string s = g();


 set<char> unique_chars(s.begin(), s.end());

 vector<char> r(unique_chars.begin(), unique_chars.end());
 sort(r.begin(), r.end());

 vector<char> r1(r);
 reverse(r1.begin(), r1.end());

 map<char, char> cnt;
 for (size_t i = 0; i < r.size(); ++i) {
 cnt[r[i]] = r1[i];
 }

 string ans;
 for (char c : s) {
 ans += cnt[c];
 }

 cout << ans << endl;
 }
 return 0;
}