/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //Approach1: With Map
    Node* helperUsingMap(Node* &head, unordered_map<Node*,Node*>& mp){
        if(!head) return 0;

        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helperUsingMap(head->next, mp);
        if(head->random){
            newHead->random = mp[head->random];
        }
        return newHead;
    }

    Node* helperUsingMap(Node* head, unordered_map<Node*,Node*>&mp){

    }

    //Approach2: Without Map
    Node* copyRandomList(Node* head){
        //Approach1: Using Map
        // unordered_map<Node*,Node*> mp;
        // return helperUsingMap(head, mp);
        //**********************************************************
        
        if(!head) return 0;

        //step1: Clone A --> A'.
        Node* it = head;  //iterate over old list
        while(it){
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        //step2: Assign random links of A' with the help of A.
        it = head;
        Node* clonedNode = NULL;
        while(it){
            clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        //step3: Detach A' from A.
        it = head;
        Node* clonedHead = it->next;
        while(it){
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }
        return clonedHead;
    }
};