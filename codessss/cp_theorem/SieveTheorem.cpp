// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Shivam     |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \_/   /
//            \  -----  /
//              \_/
  
//   Happy coding! 
// */

// /* includes and all */
// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<climits>
// using namespace std;

// int main(){
// int N;
// cin>>N;

// vector<int> lp(N+1);
// vector<int> pr;

// for (int i=2; i <= N; i++) {
//     if (lp[i] == 0) {
//         lp[i] = i;         // sieve theorem
//         pr.push_back(i);
//     }
//     for (int j = 0; i * pr[j] <= N; j++) {
//         lp[i * pr[j]] = pr[j];
//         if (pr[j] == lp[i]) {
//             break;
//         }
//     }
// }
// for(int i=0;i<pr.size();i++){
//     cout<<pr[i]<<" ";
//   }
// }
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

void sievetheorem(int n){
    vector<bool>prime(n+1,true); // initially we mark all value prime
    for(int i=2;i*i<=n;i++){
        if(prime[i]==true){
            for(int j=2*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){                         // sieve easy implementation
    if(prime[i]==true)
    cout<<i<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    sievetheorem(n);
  
}