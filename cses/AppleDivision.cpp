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
int n;
int wt[20];
using namespace std;
int f(int i,int s1,int s2){
    if(i==n) return abs(s1-s2);
    return min(f(i+1,s1+wt[i],s2),f(i+1,s1,s2+wt[i]));
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<f(0,0,0)<<endl;
}