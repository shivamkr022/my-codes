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

string f(int num){
    string res ="";
    while(num>0){
    if(num%2==0){
        res = "0"+res;  //prpend
    }
    else{
    res = "1"+res;
    }
    num=num>>1; // right shift 1 // num= num/2
    }
    return res;
}
int main(){
    int num =13;
    cout<<f(num)<<endl;
}