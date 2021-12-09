#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> listOfNumbers;

    int userInput;

    while(true){
        cout<<"Enter a number , 0 to cancel: ";
        cin>>userInput;

        if(userInput == 0){
            break;
        }

        listOfNumbers.push_back(userInput);

    }

    //iterator to read values in the list

    list<int> :: iterator i;

    cout<<"NOT SORTED"<<endl;
    for(i = listOfNumbers.begin(); i != listOfNumbers.end(); ++i){
        cout << *i << " ";

    }

    cout<<endl;

    listOfNumbers.sort();
    cout<<"SORTED"<<endl;
    for(i = listOfNumbers.begin(); i != listOfNumbers.end(); ++i){
        cout << *i << " ";

    }
    cout<<endl;

    return 0;
}