#include<iostream>
using namespace std;
//best method to find mid as work on leetcode
node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

//Approach: fast & slow
Node* findMiddle(Node* &head){
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


int main(){
    

    return 0;
}