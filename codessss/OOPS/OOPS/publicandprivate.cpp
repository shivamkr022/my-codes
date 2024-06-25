#include<iostream>;
using namespace std;

class employee{  // classs
    private:  // object(private)
    int a,b,c;

    public:  // object(public)
    int d,e;

    void setdata(int a1,int b1,int c1); // de4claring fn

    void getdata(){  // for output/print 
        cout<<" the value of a is  "<<a<<endl;
        cout<<" the value of b is  "<<b<<endl;
        cout<<" the value of c is  "<<c<<endl;
        cout<<" the value of d is  "<<d<<endl;
        cout<<" the value of e is  "<<e<<endl;
    }
};
void employee ::setdata(int a1,int b1,int c1){
    a=a1;
    b=b1;
    c=c1;
}
int main(){
    employee shivam;
   // shivam.a=22; -> it will throw error
    shivam.d=8;
    shivam.e=10;  // public data so we can use it anywhere
    shivam.setdata(2,4,6); // a,b,c are private
    shivam.getdata();

}