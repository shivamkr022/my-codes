#include<iostream>
using namespace std;
    int mazepath(int sr,int sc,int er,int ec){
    if(sr>er || sc>ec)return 0;
    if(sr==er && sc==ec)return 1;
    int downways=(sr+1,sc,er,ec);
    int rightways=(sr,sc+1,er,ec);

    int totalways = downways + rightways;
    return totalways;
}

int main(){

    cout<<mazepath(0,0,3,7)<<endl;
}