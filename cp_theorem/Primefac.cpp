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
void primefac(int n){
    
    while(n%2==0){
        cout<<2<<" ";  // all factors of 2 // i.e 2^x
        n=n/2;
    }
    for(int i=3;i*i<=n;i+=2){ // to get prime fact other than 2
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>2){
        cout<<n<<" ";  // remaining
    }
}

int main(){
    int n;
    cin>>n;
    primefac(n);
}