#include <iostream>

using namespace std;

class Enemy{

    protected:
    int attackPower;

    public:
    void set_attackPower(int ap){
        attackPower = ap;
    }

    virtual void attack(){
        cout<<"I'm an enemy"<<endl;
    }

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

        Ninja* n = new Ninja();
        Monster* m = new Monster();

        Enemy *enemy = new Enemy();

        enemy = n;

        enemy->set_attackPower(20);
        enemy->attack();

        enemy = m;
        enemy->set_attackPower(100);
        enemy->attack();

    



    return 0;

}