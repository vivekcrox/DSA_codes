class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {    
        if(!head)
            return;
        
        Node* it = head;
        for(int i=0; i<M-1; i++){
            it = it->next;
            if(!it){    //M nodes not available
                return;
            }
        }
        
        Node* MthNode = it;
        it = MthNode->next;
        Node* temp = it;
        for(int i=0; i<N; i++){
            if(!it){
                break;
            }
            temp = it->next;
            it->next = NULL;   //memory free
            delete it;
            it = temp;
        }
        MthNode->next = it;
        //recursion solve krdega aage ka
        linkdelete(it,M,N);
    }
};