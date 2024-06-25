#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "shivam";
    cout<<str<<endl;
    for(int i=0;i<sizeof(str);i++){
        if(i%2==0){
            str[i]='a';

        }
    }
    cout<<str<<endl;
}
