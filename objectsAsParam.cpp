#include <iostream>

using namespace std;

class Person{

    private:
    string firstname;
    int age;

    public:
    Person(){}
    Person(string firstname, int age){
        this->firstname = firstname;
        this->age = age;
    }

    string whoIsOlder(Person a, Person b){
        string olderPerson;

        if(a.age > b.age){
            olderPerson = a.firstname + " is older than " + b.firstname;;
        }
        else if (b.age > a.age){
            olderPerson = b.firstname + " is older than " + a.firstname;
        }
        else{
            olderPerson = a.firstname + " and " + b.firstname + " are the same! ";
        }
        return olderPerson;
    }

};


int main(){

    Person m("Danny",20);
    Person d("Nicola", 20);

    cout<<m.whoIsOlder(m, d)<<endl;



    return 0;
}