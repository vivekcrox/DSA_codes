#include<iostream>
using namespace std;


Node* reverseIterative(Node* &head){
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


Node* reverseusingRecursion(Node* prev, Node* curr) {
        //base case
        if(curr == NULL) 
                return prev;

        Node* nextPtr = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = nextPtr;

        //recursion sambhal lega
        return reverseusingRecursion(prev, curr);
}

int main(){
    

    return 0;
}