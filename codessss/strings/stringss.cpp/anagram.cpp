#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string str1 = "shivam";
    sort(str1.begin(),str1.end());

    string str2 = "vamshi";
    sort(str2.begin(),str2.end());

    if(str1==str2)cout<<true;
    else cout<<false;

}
