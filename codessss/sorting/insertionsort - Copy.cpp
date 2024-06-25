#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int array[8]={6,4,2,24,8,21,9,7};
    int n=8;
       for(int i=0;i<n;i++){ // printing the ele
        cout<<array[i]<<" ";
     }
     cout<<endl;
     for(int i=0;i<n;i++){    // insertion sort
        int j=i;
        while(j>=1){
            if(array[j]>=array[j-1]){  // condn of no swap
                break;
            }
            if(array[j]<array[j-1]){    // condn of swap
                swap(array[j],array[j-1]);
                j--;
            }

        }
     }
     for(int j=0;j<n;j++){
        cout<<array[j]<<" ";

     }
     cout<<endl;

}