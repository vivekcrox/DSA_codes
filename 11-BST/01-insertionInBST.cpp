#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) : data(d), left(NULL), right(NULL){};
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){  //first root node created
        root = new Node(data);
        return root;
    }
    if(data > root->data)
        root->right = insertIntoBST(root->right,data);
    else 
        root->left = insertIntoBST(root->left,data);
    return root;
}

void takeInput(Node* &root){
    cout<<"Enter root data: ";
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cout<<"Enter data: ";
        cin>>data;
    }
}

void preorder(Node* root){
    if(!root)
        return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    Node* root = NULL;
    takeInput(root);
    cout<<"Printing"<<endl;
    preorder(root);
    return 0;
}