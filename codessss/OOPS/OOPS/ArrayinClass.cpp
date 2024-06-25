#include<iostream>
using namespace std;
class shop{

    int itemid[100];  // creating object of array 
    int itemprice[100];  // we are using array here
    int counter=0;

    public:
    void setprice();
    void displayprice(); // creating fn of objects

};
void shop::setprice(){  // its for the item no and their price
    cout<<"enter id of your item"<< counter+1  <<endl;   // item id
    cin>>itemid[counter];
    cout<<"enter price of your item "<<endl;  // item price
    cin>>itemprice[counter];
    counter++;
}
void shop::displayprice(){  // display our item and price 
    for(int i=0;i<counter;i++){  // loop is important bec we have many items 
        cout<<"the price of the itemid "<<itemid[i]<< "is"<<itemprice[i];
    }
}

int main(){
    shop dukaan;
    dukaan.setprice();
    dukaan.setprice();
    dukaan.setprice();  // calling our functions
    dukaan.displayprice();


}