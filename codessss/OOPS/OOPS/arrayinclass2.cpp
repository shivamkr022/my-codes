#include<iostream>
using namespace std;
class shop{
    int itemid[100];  // creating object of array 
    int itemprice[100];  // we are using array here
    public:
    void setprice();
    void displayprice(); // creating fn of objects
};
void shop::setprice(){  // its for the item no and their price
    for(int i=0;i<100;i++){  // same quest using loop
    cout<<"enter id of your item"<< i+1  <<endl;   // item id
    cin>>itemid[i];
    cout<<"enter price of your item "<<endl;  // item price
    cin>>itemprice[i];
    }
}
void shop::displayprice(){  // display our item and price 
    for(int i=0;i<100;i++){  // loop is important bec we have many items 
        cout<<"the price of the itemid "<<itemid[i]<< "is"<<itemprice[i];
    }
}
int main(){
    shop dukaan;
    dukaan.setprice();  // calling our functions
    dukaan.displayprice();
}