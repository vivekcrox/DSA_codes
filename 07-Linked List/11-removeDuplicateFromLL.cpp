
/**********************************************************/
/* start your coding here...... */
   
Node* uniqueSortedList(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            Node* nodeToDelete = curr->next; 
            curr->next = curr->next->next;

            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }
        else{//not equal
            curr = curr->next;
        }
    }
    return head;
}
// Remove the Duplicates Nodes too.(Leetcode)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0, head);  // dummy->head
        ListNode* prev = dummy;
        while(head!=NULL){
            if(head->next != NULL && head->val == head->next->val){
                while(head->next!=NULL && head->val==head->next->val){
                    head=head->next;
                }
                prev->next = head->next;
            }
            else{
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};