#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int>coins;

int f(int x){
    if(x==0) return 1;
    int ans = 0;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i]<0) continue;
        ans+=f(x-coins[i]);
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int nums;
        cin>>nums;
        coins.push_back(nums);
    }
    cout<<f(x)<<"\n";
}