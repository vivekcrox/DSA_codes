#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) : data(d), left(NULL), right(NULL) {};
};
/* BuildTree Using Recursion */
Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root = new Node(data);

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
/* BuildTree From level Order Traversal */
void buildTreeFromLevelOrder(Node* &root){
    cout<<"Enter data for root: ";
    int data; cin>>data;
    if(data == -1)
        return;
    root = new Node(data);
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<" : ";
        int leftData; cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<" : ";
        int rightData; cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrder(Node* root){
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;     // old level conplete ho chuka h.
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

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

int main(){
    Node* root = NULL;
    //creating the tree
    root = buildTree(root);
    // buildTreeFromLevelOrder(root);
    cout<<endl<<"Level Order Traversal: "<<endl;
    levelOrder(root);

    return 0;
}