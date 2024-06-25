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

int f(string & bin){
    int n = bin.length();
    int res = 0; // legth
    for(int i=n-1;i>=0;i--){
        char ch=bin[i]; // every char of string
        int num =ch-'0'; // convert char 0 and 1 into numbers
        res=res+num*(1<<(n-i-1));
    }
    return res;
}

int main(){
    string str="00111001011110000010100101000000";
    cout<<f(str)<<"\n";
    return 0;
}