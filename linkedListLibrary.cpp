#include <iostream>
#include <list>

using namespace std;

void showList(list<int> &l){
    list<int> :: iterator i ;
    for(i=l.begin();i !=l.end(); i++){
        cout<< *i <<" ";
    }
    cout<<endl;
}


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
    showList(listOfNumbers);

    listOfNumbers.sort();
    cout<<"SORTED"<<endl;
    showList(listOfNumbers);

    cout<<"Pushing back"<<endl;
    listOfNumbers.push_back(500);
    showList(listOfNumbers);

    cout<<"INserting 300 at second position"<<endl;

    i = listOfNumbers.begin();
    listOfNumbers.insert(++i, 300);
    showList(listOfNumbers);

    cout<<"Inserting 600 second last position"<<endl;

    i = listOfNumbers.end();
    listOfNumbers.insert(--i, 600);
    showList(listOfNumbers);

    cout<<"Deleting first element"<<endl;
    //storing value of first element in a variable before poping it out
    int x;
    i = listOfNumbers.begin();
    x = *i;
    listOfNumbers.pop_front();
    showList(listOfNumbers);

    cout<<"Deleting last element"<<endl;
    //use x variable
    
    //setting iterator to end
    i = listOfNumbers.end();
    x = *i;
    listOfNumbers.pop_back();
    showList(listOfNumbers);

    cout<<"Empty the list"<<endl;
    listOfNumbers.clear();
    showList(listOfNumbers);
    





    
    



    return 0;
}