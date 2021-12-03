#include <iostream>

using namespace std;

class Person{

    private:
    string firstname, surname;
    int year;

    public:
    Person(){}
    ~Person(){
        cout<<"deleted!"<<endl;
    }
    Person(string firstname, string surname, int year){
        this->firstname = firstname;
        this->surname = surname;
        this->year = year;
    }

    void printData(){
        cout<<firstname <<", "<<surname<<", "<<year<<endl;

    }

};

int main(){

    Person *persons[10];
    
    for(int i=0;i<10;i++){
        persons[i] = new Person("p", "l", 2000+i);
    }

    for(int i=0; i<10; i++){
        persons[i]->printData();
    }

    for(int i=0;i<10;i++){
        delete persons[i];
    }

    return 0;
}