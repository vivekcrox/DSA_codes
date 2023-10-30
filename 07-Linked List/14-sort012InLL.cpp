
/**********************************************************/
/* start your coding here...... */
//Approach1: counting method
void sortZeroOneTwo(Node* &head) {
        //step1: find count of zeroes, ones and twos
        int zero = 0;
        int one = 0;
        int two = 0;

        Node* temp = head;
        while(temp != NULL) {
                if(temp -> data == 0)
                        zero++;
                else if(temp -> data == 1)
                        one++;
                else if(temp -> data == 2)
                        two++;
                temp = temp -> next;
        }

        //step2: fill 0, 1 and 2s in the original ll
        temp = head;
                // fill zeroes
                while(zero--) {
                        temp -> data = 0;
                        temp = temp -> next;
                }

                //fill ones
                while(one--) {
                        temp -> data = 1;
                        temp = temp -> next;
                }

                //fill 2s
                while(two--) {
                        temp -> data = 2;
                        temp = temp -> next;
                }
}

//Approach2: Using dummy nodes
void insertAtTail2(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail2(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail2(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail2(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head, tail, 2, 1);
    insertAtPosition(head, tail, 0, 2);
    insertAtPosition(head, tail, 0, 3);
    insertAtPosition(head, tail, 1, 4);
    insertAtPosition(head, tail, 2, 5);
    insertAtPosition(head, tail, 0, 6);
    insertAtPosition(head, tail, 1, 7);
    insertAtPosition(head, tail, 2, 8);
    insertAtPosition(head, tail, 1, 9);

    print(head);

    Node* head1 = sortList(head);
    print(head1);
 
    return 0;
}