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
void subset(string ans,string orig,vector<string>&s){
    if(orig==""){
       s.push_back(ans);
       return;
    }
    char ch=orig[0];
    subset(ans,orig.substr(1),s);
    subset(ans+ch,orig.substr(1),s);
}
int main(){
    string str;
    cin>>str;

    vector<string>s;
    subset("",str,s);

    for(string ele:s){
        cout<<ele<<" "<<endl;
    }
}