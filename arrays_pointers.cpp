#include <iostream>

using namespace std;

void increment(int *start, int *end){
    int *address_val = start;

    while(address_val != end){
        (*address_val)++; // incrementing array index val
        address_val++; //incrementing address val
        
    }

}

void print_all(int *start, int *end){

    int *add_val = start;

    while(add_val != end){
        cout<<*add_val<<endl; //printing out array elements
        add_val++;
        
    }

}


int main(){

    int numbers[] = {1,2,3,4};
    increment(numbers, numbers+4); // numbers = mem address of first element in the array & numbers +4 = add. of last element
    print_all(numbers, numbers+4);

    return 0;
}