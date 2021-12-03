#include <iostream>

using namespace std;

class Rectangle{

    private:
    float height;
    float width;
    float area;

    public:
    Rectangle(){}

    Rectangle(float width, float height){
        this->width = width;
        this->height = height;
        area = width * height;
    }

    ~Rectangle(){
        cout<<"Free up memory, object deleted!"<<endl;
    }

    float return_area(){
        return area;
    }

};


int main(){

    float w, h;
    Rectangle *rectangle = new Rectangle;
    //repeat process until one of the variables is equal to zero

    while (true)
    {
        cout<<"Width: ";
        cin>>w;
        cout<<"Height: ";
        cin>>h;
        if(w == 0 || h == 0){
            break;
        }
        rectangle = new Rectangle(w,h);
        cout<<rectangle->return_area()<<endl;
    }

    delete rectangle;
    

    return 0;
}