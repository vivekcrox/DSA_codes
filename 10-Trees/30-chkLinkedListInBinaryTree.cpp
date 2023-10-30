/* Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False. */
class Solution {
public:
    bool find(ListNode* head, TreeNode* root){
        if(head == NULL) 
            return true;
        if(root == NULL) 
            return false;
        if(root->val == head->val)
            return find(head->next,root->left) || find(head->next,root->right);
        else 
            return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        return find(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};