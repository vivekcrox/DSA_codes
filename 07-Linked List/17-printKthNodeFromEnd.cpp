//Recursive solution
void fun(Node* head, int& positionFromTail, int& ans){
    if(head==NULL){
        return;
    }

    fun(head->next, positionFromTail, ans);
    //now reach last node
    if(positionFromTail == 0){
        ans = head->data;
    }
    positionFromTail--;
}

int getNode(Node* head, int positionFromTail){
    int ans = -1;
    fun(head, positionFromTail, ans);
    return ans;
}