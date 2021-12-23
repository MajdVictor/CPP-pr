#include <iostream>

using namespace std;

class Enemy{
    //Abstract class , cannot be instantiated 
    //the virtual function which needs to be implemented in the derived class must equal to zero here
    protected:
    int attackPower;

    public:
    void set_attackPower(int ap){
        attackPower = ap;
    }

    virtual void attack() = 0;

};

class Ninja: public Enemy{

    public:
    void attack(){
        cout<<"Ninja attacking! "<<attackPower<<endl;

    }
};
class Monster: public Enemy{

    public:
    void attack(){
        cout<<"Monster attacking! "<<attackPower<<endl;
    }
};

int main(){

        /*if we don't override the virtual function , it throws an error*/
        Ninja* n = new Ninja();
        Monster* m = new Monster();

        // Enemy *enemy = new Enemy()   ... cannot create an instance of the abstract class
        Enemy *enemy; //pointer which points to nothing. used to point to different derived classes objects

        enemy = n;

        enemy->set_attackPower(20);
        enemy->attack();

        enemy = m;
        enemy->set_attackPower(100);
        enemy->attack();

    



    return 0;

}