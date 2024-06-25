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
bool cmp(pair<int,int>&a,pair<int,int>&b){
  return (a.second<b.second);
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    sort(s.begin(),s.end(),cmp); // to sort the finishing time of each movie;
    int fintimeoflastmovie=-1;
    int moviewatch=0;
    int i=0;
    while(i<n){
      if(s[i].first>=fintimeoflastmovie){  // if this condn satisfy then we able to watch next movie
        moviewatch++;
        fintimeoflastmovie=s[i].second;  // updatinf finishing time
        i++;
      }
      else  // if not watch move to next
      i++;
    }
    cout<<moviewatch<<endl;

}