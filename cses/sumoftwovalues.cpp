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
#include<map>
using namespace std;

int main(){
    int n,tar; // array size , target
    cin>>n>>tar; // input
    vector<int>ans;  // to store ans
    vector<int> nums(n); // given vector
    for(int i=0;i<n;i++) cin>>nums[i];

    map<int,int>mp;
     for(int i=0;i<n;i++){
        int rem = tar-nums[i];
        if(mp.find(rem)!=mp.end()){    // rem is present
          ans.push_back(mp[rem]);  // mp[rem] -> rem ka index
          ans.push_back(i);
        } 
        else mp[nums[i]]=i; // mp[nums[i]]->key , i->value
      }
      if(ans.size()!=0){
      for(int x : ans){
        cout<<(x+1)<<" ";
         }
      }
      else cout<<"IMPOSSIBLE"<<endl;
}