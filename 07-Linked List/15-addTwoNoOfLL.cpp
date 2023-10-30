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
/**********************************************************/
/* start your coding here...... */

Node* reverse(Node* &head){
        if(head==NULL){
                return head;
        }
        Node* prevPtr = NULL;
        Node* curr = head;
        Node* nextPtr = NULL;
        while(curr != NULL){
                nextPtr = curr->next;
                curr->next = prevPtr;
                prevPtr = curr;
                curr = nextPtr;
        }
        return prevPtr;
}

Node* addHelper(Node* &first, Node* &second){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0){
        //extract val from both list
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }
        int val2 = 0;
        if(second != NULL){
            val2 = second->data;
        }

        int sum = carry+val1+val2;
        int digit = sum%10;
        //create node & add in answer list
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;

        if(first!=NULL)
            first = first->next;
        if(second!=NULL)
            second = second->next;
    }
    return ansHead;
}

Node* addTwoList(Node* first, Node* second){
    first = reverse(first);
    second = reverse(second);

    Node* ans = addHelper(first, second);
    ans = reverse(ans);
    return ans;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head, tail, 10, 1);
    insertAtPosition(head, tail, 20, 2);
    insertAtPosition(head, tail, 30, 3);
    insertAtPosition(head, tail, 40, 4);
    insertAtPosition(head, tail, 50, 5);
    insertAtPosition(head, tail, 60, 6);
    insertAtPosition(head, tail, 70, 7);
    insertAtPosition(head, tail, 80, 8);
    insertAtPosition(head, tail, 90, 9);

    print(head);


 
    return 0;
}