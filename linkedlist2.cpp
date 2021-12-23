#include <iostream>

using namespace std;

class Person{
    //reflexive association

    friend class ListOfPeople;

    private:
    string firstname;
    string lastname;
    int age;
    
    Person *next;

    public:
    Person(string firstname, string lastname, int age){
        this->firstname = firstname;
        this->lastname = lastname;
        this->age = age;
        next = NULL;
    }

    Person *next(){
        return next;
    }


};

class ListOfPeople{

    private:
    Person *headNode;


    public:
    ListOfPeople(){
        headNode = NULL;
    }

    void insert(Person *newNode){
        headNode->next = newNode;
        headNode = newNode;
    }


};

int main(){




    
    return 0;
}