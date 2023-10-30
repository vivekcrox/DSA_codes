    bool usingBfs(int src, vector<int>&visited, vector<int> adj[]){
        visited[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto nbr: adj[node]){
                if(!visited[nbr]){
                    q.push({nbr, node});
                    visited[nbr] = 1;
                }
                else if(nbr != parent)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i])
                if(usingBfs(i, visited, adj) == true) return true;
        }
        return false;
    }