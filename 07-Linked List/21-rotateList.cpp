/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;

        int len = getLen(head);
        int actualRotateK = k%len;
        if(actualRotateK == 0)
            return head;

        int newTailPos = len - actualRotateK - 1;
        ListNode* newTail = head;
        for(int i=0; i<newTailPos; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = 0;

        ListNode* it = newHead;
        while(it->next){
            it=it->next;
        }
        it->next = head;
        return newHead;
    }
};