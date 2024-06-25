#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string str = "shivam";
    cout<<str<<endl;

    reverse(str.begin(),str.end()-3);
    cout<<str<<endl;
    
}
