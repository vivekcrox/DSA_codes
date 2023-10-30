class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int diff = 0;
        ListNode* ptr1;
        ListNode* ptr2;
        if(l1 > l2){
            diff = l1 - l2;
            ptr1 = headA;
            ptr2 = headB;
        }
        else{
            diff = l2 - l1;
            ptr1 = headB;
            ptr2 = headA;
        }

        while(diff){
            ptr1 = ptr1->next;
            if(ptr1==NULL){
                return NULL;
            }
            diff--;
        }
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 == ptr2){
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};