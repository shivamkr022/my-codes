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
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
int n; // input
cin>>n;
vector<pair<int,int>> v;
for(int i=0;i<n;i++){
  int entry,exit;
  cin>>entry>>exit; // takong input of pair
  v.push_back({entry,1});  // entry m ek badh jayega
  v.push_back({exit,-1});  // exit m ek person kam ho jayega
}
sort(v.begin(),v.end());  // sort for answer
int curr=0;
int ans =0;
for(int i=0;i<v.size();i++){
  curr+=v[i].second;  // just observation
  ans=max(ans,curr);

}
cout<<ans<<endl;

}