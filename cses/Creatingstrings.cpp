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
#define ll long long int
#define mod 1000000007
using namespace std;
int main(){
  string s;
  cin>>s; // input
  sort(s.begin(),s.end()); // sorting
  vector<string>ans; // to store ans
  do{
      ans.push_back(s);
  }
  while(next_permutation(s.begin(),s.end()));
  cout<<ans.size()<<"\n";
  for(string str : ans){
    cout<<str<<"\n";
  }
  return 0;
}