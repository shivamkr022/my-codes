#include<iostream>
#include<vector>
using namespace std;

int main(){
    int array[8]={0,4,2,0,8,0,9,7};
    int n=8;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(array[j]==0 && array[j+1]>0){ // push zeroes to the end
                swap(array[j],array[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    

}