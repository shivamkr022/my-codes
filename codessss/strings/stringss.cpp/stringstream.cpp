#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string str = "shivam is a student";
    
    stringstream ss(str);
    string temp;

    while(ss>>temp){
        cout<<temp<<endl;
    }
}
