#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;           //here front=rear=0 --> rear points to empty cell in Q
        }


        void push(int data){
            if(rear == size){
                cout<<"Queue is full"<<endl;
            }
            else{
                arr[rear] = data;
                rear++;
            }
        }

        void pop(){
            if(front == rear){
                cout<<"Queue is empty"<<endl;
            }
            else{
                arr[front] = -1;
                front++;
                if(front == rear){ //move to starting point
                    front = rear = 0; 
                }
            }
        }

        int getFront(){
            if(front == rear){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else{
                return false;
            }
        }

        int getSize(){
            return rear - front;
        }
};


int main(){
    Queue q(4);
    q.push(5);
    q.push(6);
    q.push(3);
    q.push(2);

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    q.pop();
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    q.pop();
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    q.pop();
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    q.pop();
    cout<<q.getFront()<<endl;

    return 0;
}