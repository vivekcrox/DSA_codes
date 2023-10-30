#include<iostream>
using namespace std;

class A{
    private:
        int x;

    public:
        A(int _val) : x(_val){};

        int getX() const {
            return x;
        }
        void setX(int _val){
            x = _val;
        }

        friend class B;    // now a.x can be accessed by class B
        friend void print(const A &a);
};

class B{
    public:
        void print(const A &a){
            // cout<< a.getX() <<endl;
            cout<< a.x <<endl;  // error as x is private but after friend class B in class A -> it will run :)
        }
};

void print(const A &a){
    cout<< a.x << endl;   //after making friend it will allowed to access private members
}

int main(){
    A a(5);
    
    B b;
    b.print(a);
    print(a);
    return 0;
}