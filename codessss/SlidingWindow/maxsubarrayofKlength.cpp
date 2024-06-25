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
//     int arr[]={7,1,2,5,8,4,9,3,6};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k=3;
//     int maxsum=INT_MIN;
//     for(int i=0;i<=n-k;i++){
//         int sum=0;                          // brute force
//         for(int j=i;j<i+k;j++){
//             sum+=arr[j];
//         }
//         maxsum=max(maxsum,sum);
//     }
//     cout<<maxsum<<endl;
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

int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int prevsum=0;

    for(int i=0;i<k;i++){
        prevsum+=arr[i];
    }
    int maxsum=prevsum;
    int i=1;                                     ///// sliding window approach
    int j=k;
    while(j<n){
        prevsum=prevsum+arr[j]-arr[i-1];
        if(prevsum>maxsum){
            maxsum=prevsum;
        }
        i++;
        j++;
    }
    cout<<maxsum<<endl;
}