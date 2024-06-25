#include<iostream>
using namespace std;
class student{ // user defined datatype
    public:
    string name;
    int rollno;
    float percent;
    student(string n,int r,float p){  // its a default constructor
        name=n;
        rollno=r;
        percent=p;

    }
};
int main(){
    student s={"shivam",6,91.66};
    cout<<s.name<<endl;
}