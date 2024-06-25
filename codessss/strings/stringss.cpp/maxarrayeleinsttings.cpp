#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string str[]={"012","598","439","830"};
    int max =stoi(str[0]);
    for(int i=0;i<4;i++){
        int x=stoi(str[i]);
        if(x>max)max=x;

    }
    cout<<max;
     
    }