#include <iostream>

using namespace std;

class AA{
    
    private:
    int x,y;

    public:
    AA();
    AA(int a, int b){
        x= a;
        y=b;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};


int main(){

    AA obj1(1,2);

    AA *obj1P  =  &obj1;

    cout<<obj1P->getX()<<" "<<obj1P->getY()<<endl;
    



    return 0;
}