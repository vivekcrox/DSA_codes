#include<iostream>
using namespace std;

//** This instance is used in real-life where only boxfactory give permission to make a box, and no other can make box without calling boxfactory.

class Box{
    int width;
    //ctor - in private
    Box(int _w) : width(_w){};

    public:

        int getWidth() const {
            return width;
        }
        void setWidth(int _val){
            width = _val;
        }
        friend class BoxFactory;
};

class BoxFactory{
    int count;   //this count var is used when we want to track the number of boxes manufactured.
    public:
        Box getABox(int _w){
            ++count;
            return Box(_w);
        }
};



int main(){
    // **below 2 lines gives 'ERROR' before 'friend' keyword
    // Box b(5);
    // cout<< b.getWidth() <<endl;

    BoxFactory bfact;
    Box b = bfact.getABox(5);
    cout<< b.getWidth() <<endl;
    return 0;
}