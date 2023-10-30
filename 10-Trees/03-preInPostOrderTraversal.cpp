/*content:
    1. Recursively
    2. Iteratively
    3. All in one traversal
*/
// 1. Recursively
void preOrder(Node* root){
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root==NULL)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
/*****************************************************************************/
// 2. Iteratively
vector<int> preOrderIter(Node* root){  // using 1 stack.
    vector<int> preorder;
    if(root==NULL)
        return preorder;
    
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        preorder.push_back(temp->data);

        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }
    return preorder;
}

vector<int> inOrderIter(Node* root){
    vector<int> inorder;
    if(root==NULL)  
        return inorder;

    stack<Node*> st;
    Node* curr = root;

    while(true){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(st.empty())
                break;
            
            curr = st.top();
            st.pop();
            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }
    return inorder;
}

//postorder using 2 stacks
vector<int> postOrderIter2stack(Node* root){
    vector<int> postorder;
    if(root==NULL)
        return postorder;

    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if(curr->left)
            st1.push(curr->left);
        if(curr->right)
            st1.push(curr->right);
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}
//postorder using 1 stack
vector<int> postOrder1stack(Node* root){
    vector<int> postorder;
    if(root==NULL)
        return postorder;
    
    stack<Node*> st;
    Node* curr = root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }
    return postorder;
}
/*******************/
// 3. Pre | In | Postorder Traversal in one traversal
void preInPost(Node* root, vector<int>& pre, vector<int>& in, vector<int>& post){
    vector<int> pre, in, post;
    if(root == NULL)   
        return ;
    
    stack<pair<Node*,int> > st;
    st.push({root,1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left)
                st.push({it.first->left, 1});
        }
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right)
                st.push_back({it.first->right, 1});
        }
        else{
            post.push_back(it.first->data);
        }
    }
}
