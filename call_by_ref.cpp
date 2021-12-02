#include <iostream>

using namespace std;

void swap(int &x, int &y){
    
    int temp = x;
    x = y;
    y = temp;


}

int main(){

    int a = 6, b=7;
    cout<<a<<b<<endl;
    swap(a, b);
    cout<<a<<b<<endl;

    return 0;
}