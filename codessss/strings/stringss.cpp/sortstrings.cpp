#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string str = "shivamm";
    int max =0;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        int count=1;
        for(int j=i+1;i<str.length();j++){
            if(str[j]==str[i])count++;
        }
        if(max<count) max=count;

    }
    cout<<max;
     
    }