#include <iostream>

using namespace std;

int main(){

    int sizeOfArray;
    int num;

    cout<<"Size of array: ";
    cin>>sizeOfArray;

    int *arr = new int[sizeOfArray];

    for (int i=0; i< sizeOfArray; i++){
        cout<<"num "<<i+1<<" : ";
        cin>>num;
        arr[i] = num;
    }

    for(int x= 0; x<sizeOfArray; x++){
        cout<<arr[x]<<endl;
    }

    delete [] arr;
    return 0;
}