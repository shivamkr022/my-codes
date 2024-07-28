#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#define ll long long int
#define mod 1000000007
using namespace std;

ll f(ll a, ll b){
    if(b == 0) return 1;
    ll res = f(a, b / 2);
    res = (res * res) ; // Ensure the result is taken modulo at each step
    if(b % 2 == 1){
        return (res * a);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        ll a, b; // Change 'int' to 'll' to handle larger values
        cin >> a >> b;
        cout << f(a, b) << endl;
    }
}
