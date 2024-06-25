#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int array[8]={6,4,2,24,8,21,9,7};
    int n=8;
       for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
     }
     cout<<endl;

    for(int i=0;i<n-1;i++){
     int min =INT16_MAX;
     int mindx=-1;

    for(int j=i;j<n;j++){
        if(array[j]<min){
            min=array[j];
            mindx=j;
        }
    }
    swap(array[i],array[mindx]);
    }
     for(int j=0;j<n;j++){
        cout<<array[j]<<" ";

     }
     cout<<endl;

}