class Solution {
  public:
    // create mapping & return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;   //root node parent is null
        
        while(!q.empty()){   //level order traversal
            Node* front = q.front();
            q.pop();
            
            if(front->data == target)
                res = front;
            
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        int time = 0;
        while(!q.empty()){  
            bool flag = 0;     //check any addition to queue
            int size = q.size();
            for(int i=0; i<size; i++){    // process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){   //process left node
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if(front->right && !visited[front->right]){   //process right node
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){   //process parent node
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1){    //if queue m addition hua toh time++;
                time++;
            }
        }
        return time;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root,target,nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};