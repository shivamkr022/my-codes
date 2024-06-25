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

int countsetbits(int n){  //brian kernighans algo
    int count=0;
    while(n>0){
        count++ ; // count the iterations
        n=(n&(n-1));
    }
    return count;
}

 // my approach
int countsetbits2(int n){
    int count1=0;
    while(n>0){
        if(n%2==1){
            count1++;    // my approach
            n=n>>1;
        }
        else{
            n=n>>1;
        }
    }
    return count1;
}

int countsetbits3(int n){ // inbuilt function
 
    return __builtin_popcount(n);
}

int main(){
 
    cout<<countsetbits(13)<<endl;
    cout<<countsetbits2(13)<<endl;
    cout<<countsetbits3(13)<<endl;
}