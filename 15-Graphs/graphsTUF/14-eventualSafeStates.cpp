class Solution {
  public:
    bool dfsCycleChk(int node, vector<int>adj[], vector<int>& vis, vector<int>& dfsVis, vector<int>&safe){
        vis[node] = 1;
        dfsVis[node] = 1;
        safe[node] = 0;
        
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                if(dfsCycleChk(nbr,adj,vis,dfsVis,safe)==true){
                    return true;
                }
            }
            // if the node has been prev visited burt it has to be vis on the same path.
            else if(dfsVis[nbr]){
                return true;
            }
        }
        safe[node] = 1;
        dfsVis[node] = 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // vector<int> dfsVis(V,0);
        // vector<int> vis(V,0);
        // vector<int> safe(V, 0);
        
        // for(int i=0; i<V; i++){
        //     if(!vis[i]){
        //         if(dfsCycleChk(i, adj, vis, dfsVis, safe)==true){
        //             safe[i] = 0;
        //         }
        //     }
        // }
        
        // vector<int> safeNodes;
        // for(int i=0; i<V; i++){
        //     if(safe[i]==1)
        //         safeNodes.push_back(i);
        // }
        // return safeNodes;
        
        
        // 2. Using Topological(BFS)
        vector<int> adjRev[V];    // store adj list by reversing the edges in the graph & apply topo.
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto nbr: adj[i]){
                adjRev[nbr].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto nbr: adjRev[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());  // to get ans in increasing order.
        return safeNodes;
    }
};