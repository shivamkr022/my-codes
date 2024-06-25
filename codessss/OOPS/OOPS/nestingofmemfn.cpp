#include<iostream>
#include<string>
using namespace std;

class binary {
    string s; // taking string 
    public:
    void read();  // declaring fn
    void check_binary();  // declaring fn for check binary or not
};
void binary::read(void){
    cout<<"enter a binary number  "<<endl;  // for taking input as a binary
    cin>>s;
}
void binary ::check_binary(){  
    for(int i=0;i<s.length();i++){
        if(s[i]!='0' && s[i]!='1'){   // condn for check binary or not
            cout<<"not a binary format"<<endl;
        }
    }
}
int main(){
    binary s;
    s.read();  // for read the binary number
    s.check_binary();  // for check the binary number 
}