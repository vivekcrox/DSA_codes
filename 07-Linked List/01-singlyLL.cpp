#include<iostream>
using namespace std;

class Node{
        public:
                int data;
                Node* next;
                //ctor
                Node(int data){
                        this->data = data;
                        this->next = NULL;
                }
                //dtor
                ~Node(){
                        int value = this->data;
                        if(this->next != NULL){
                                delete next;
                                this->next = NULL;
                        }
                        cout<<"Memory is free for node with data: "<<value<<endl;
                }
};

void print(Node* &head){
        if(head  == NULL){
                cout<<"List is empty!!"<<endl;
                return;
        }

        Node* temp = head;
        while(temp != NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
        }
        cout<<"x"<<endl;
}

int lenLL(Node* &head){
        int len = 0;
        Node* temp = head;
        while(temp!=NULL){
                len++;
                temp = temp->next;
        }
        return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);

        if(head == NULL){ //LL is empty
                head = newNode;
                tail = newNode;
                return;
        }
        //LL is non-empty
        newNode->next = head;
        head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){ //LL is empty
                head = newNode;
                tail = newNode;
                return;
        }
        //LL is non-empty
        tail->next = newNode;
        tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
        //if position given by user >= (lenLL + 2)
        if(position > lenLL(head)+1){
                cout<<"Invalid position!!"<<endl;
                return;
        }
        //insert at start
        if(position == 1){
                insertAtHead(head, tail, data);
                return;
        }

        Node* prevNode = head;
        int i=1;
        while(i < position-1){
                prevNode = prevNode->next;
                i++;
        }

        //inserting at last position
        if(prevNode->next == NULL){
                insertAtTail(head, tail, data);
                return;
        }

        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
}

void deletionFromPos(Node* &head, Node* &tail, int position){
        if(position > lenLL(head)){
                cout<<"Invalid position for deletion!!"<<endl;
                return;
        }

        if(head == NULL){
                cout<<"List is empty!!"<<endl;
                return;
        }
        if(position == 1){ //deleting start node
                Node* temp = head;
                head = head->next;
                //memory free
                temp->next = NULL;
                delete temp;
                return;
        }
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int i=1;
        while(i < position){
                prev = curr;
                curr = curr->next;
                i++;
        }

        prev->next = curr->next;
        if(curr->next == NULL){ //deleting last node
                tail = prev;
        }
        //memory free
        curr->next = NULL;
        delete curr;
}

void deletionByVal(Node* &head, Node* &tail, int value){
        //** "delete" giving error!! (may be dtor is wrong) 

        if(head == NULL){
                cout<<"List is empty!!"<<endl;
                return;
        }
        if(head->next == NULL && head->data == value){
                //deleting single node of given value
                Node* todelete = head;
                head = NULL;
                tail = NULL;
                // delete todelete;
                return;
        }
        cout<<"OK!!!"<<endl;
        
        if(head->data == value){ //deleting first node
                Node* temp = head;
                head = head->next;
                temp->next == NULL;
                // delete temp;
                return;
        }
        cout<<"OKaodfoafaf"<<endl;
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != value ){
                temp = temp->next;
        }
        if(temp->next == NULL){
                cout<<"Given value is not present!!"<<endl;
                return;
        }
        if(temp->next->next == NULL){ //deleting last node
                tail = temp;
        }
        Node* todelete = temp->next;
        temp->next = temp->next->next;
        // delete todelete;
}


int main(){
        Node* head = NULL;
        Node* tail = NULL;

        // insertAtHead(head, tail, 10);
        // insertAtHead(head, tail, 20);
        // insertAtHead(head, tail, 30);

        // insertAtTail(head, tail, 10);
        // insertAtTail(head, tail, 20);
        // insertAtTail(head, tail, 30);

        insertAtPosition(head, tail, 10, 1);
        insertAtPosition(head, tail, 20, 2);
        insertAtPosition(head, tail, 30, 3);
        insertAtPosition(head, tail, 40, 4);
        insertAtPosition(head, tail, 50, 5);

        print(head);
        if(head != NULL && tail != NULL){
                cout<<"Head: "<<head->data<<endl;
                cout<<"Tail: "<<tail->data<<endl;
        }else{
                cout<<"head & tail: NULL"<<endl;
        }

        // deletionFromPos(head, tail, 3);
        // deletionByVal(head, tail, 10);

        print(head);
        if(head != NULL && tail != NULL){
                cout<<"Head: "<<head->data<<endl;
                cout<<"Tail: "<<tail->data<<endl;
        }else{
                cout<<"head & tail: NULL"<<endl;
        }

        return 0;
}