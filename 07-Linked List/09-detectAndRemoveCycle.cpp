#include<iostream>
#include<unordered_map>
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

//1. Detect Loops :
//Approach1: Using Map
bool detectLoop(Node* &head){
    if(head==NULL){
        return false;
    }

    unordered_map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            cout<<"Present on element "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

//Approach2: Floyd's cycle detection algo
Node* floydDetectLoop(Node* &head){
        if(head == NULL){
                return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL){
                fast = fast->next;
                if(fast!=NULL){
                        fast = fast->next;
                }
                slow = slow->next;
                //check for cycle
                if(fast == slow){
                        return slow;
                }
        }
        return NULL;
}

//2. Find starting node of loop
Node* getStartingNode(Node* &head){
        if(head == NULL){
                return NULL;
        }

        Node* intersection = floydDetectLoop(head);

        Node* slow = head;
        while(slow != intersection){
                slow = slow->next;
                intersection = intersection->next;
        }
        return slow;
}

//3. Remove Loop
void removeLoop(Node* &head){
        if(head == NULL){
                return;
        }

        Node* startOfLoop = getStartingNode(head);
        Node* temp = startOfLoop;
        while(temp->next != startOfLoop){
                temp = temp->next;
        }
        temp->next = NULL;
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

    //making circular LL
    Node* last = new Node(100);
    tail->next = last;
    tail = last;
    last->next = head->next->next;

//     print(head);
        if(floydDetectLoop(head)!=NULL){
                cout<<floydDetectLoop(head)->data<<endl;
        }
        else{
                cout<<"loop not present"<<endl;
        }

        cout<<getStartingNode(head)->data<<endl;
        removeLoop(head);
        print(head);

    return 0;
}