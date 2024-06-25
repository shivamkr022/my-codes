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
// bool cmp(pair<int,int>&a,pair<int,int>&b){
//   return (a.second<b.second);
// }

int main(){
    int n;
    cin>>n;
    
    vector<pair<int,int>> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    sort(s.begin(),s.end()); // to sort the finishing time of each movie;
    int roomreq=0;
    int lastexit=-1;
    int i=0;
    int key=1;
    vector<int>ans;
    while(i<n){
        if(lastexit<s[i].first){
           // ans.push_back(key);
           roomreq++;
            lastexit=s[i].second;
            i++;
           // key++;
        }
        else{
            roomreq++;
            i++;
          //  ans.push_back(key++);
        }
    }
    cout<<roomreq<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}