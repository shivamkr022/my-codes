#include<iostream>
#include<vector>
using namespace std;

class Maxheap{
    // private by default
    vector<int>hp; // vector to stote the element
    void upheapify(int ci){  // ci = child idex  // 0 index p parent nodr h0ga
    while(ci>0){
        int pi =(ci-1)/2;
        if(hp[ci]>hp[pi]){   // Max heap prp is that pn>cn  // parent node  // and change the sign fot Minhip
            swap(hp[pi],hp[ci]);
            ci=pi; // pn and cn changed now
        }
        else{
            break;
        }
    }
}
public:

void push(int element){  // add element in the heap
hp.push_back(element);
upheapify(hp.size()-1);  // calling the fn as the last ele present at the last idx

}
bool empty(){   // heap is empty
    return hp.size()==0;
}
void display(){   // to print the ele of heap
    for(int i=0;i<hp.size();i++){
        cout<<hp[i]<<" ";
    }
  }
};
int main(){
    Maxheap hp; // for pushing the ele in heap
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    hp.display();

}