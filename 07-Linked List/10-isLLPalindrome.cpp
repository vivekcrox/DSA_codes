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

Node* getMid(Node* &head){
    if(head==NULL || head->next == NULL || head->next->next == NULL){ // assuming left node as an answer 
        return head;
    }

    Node* temp = head;
    Node* slow = temp;
    Node* fast = temp->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
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

bool isPalindrome(Node* &head){
    if(head==NULL || head->next == NULL){
        return true;
    }

    Node* middle = getMid(head);
    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;
    while(head2 != NULL){
        if(head2->data != head1->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // to again make original LL
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
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