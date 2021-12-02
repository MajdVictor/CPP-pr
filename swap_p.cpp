#include <iostream>

using namespace std;

void swap(int *x, int *y){

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

int main(){

    int x = 10, y = 15;

    cout<<"X: "<<x<<endl;
    cout<<"Y: "<<y<<endl;

    cout<<"After swap----"<<endl;
    swap(&x, &y);

    cout<<"X: "<<x<<endl;
    cout<<"Y: "<<y<<endl;

    return 0;

}