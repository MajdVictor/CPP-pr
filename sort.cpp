#include <iostream>

using namespace std;

void sort (int *x){   //bubble sort
    int temp;
    for(int i = 0; i<10; i++){
        for(int j =0; j<10-i-1; j++){
            if(x[j]>x[j+1]){
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
	
}

int main (){

    int a [10], i;

    cout << "Unsorted Array : " << endl;
    for ( i =0; i <10; i ++)
    {
        a [i]= rand()%100;
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Sorted Array : " << endl;
    sort(a);
    for ( i =0; i <10; i ++)
        cout << a[i] << " ";
        
    cout << endl;

    return 0;
}

