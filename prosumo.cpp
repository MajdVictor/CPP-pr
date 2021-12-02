#include <iostream>

using namespace std;

void prosumo(int size, int *arr, int *resp, int *resum){

    for(int i=0; i<size; i++){
        *resum += arr[i];
        *resp *= arr[i];

    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    int s = 5;
    int prod_res = 1;
    int sum_res = 0;

    prosumo(s, arr, &prod_res, &sum_res);
    cout<<"Sum: "<<sum_res<<endl;
    cout<<"Prod: "<<prod_res<<endl;

    return 0;
}