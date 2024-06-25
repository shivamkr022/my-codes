#include<iostream>
using namespace std;
class student{ // user defined datatype
    public:
    string name;
    int rollno;
    float percent;
};
int main(){
    student s; // initialisation

    s.name="shivam";  // declaration
    s.rollno=6;          // declaration
    s.percent=91.33;         // declaration
    cout<<s.name<<endl;
}