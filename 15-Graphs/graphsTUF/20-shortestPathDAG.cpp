class Solution {
  public:
    void topoUsingDfs(int node, stack<int>& st, vector<int>& vis, vector<pair<int,int>> adj[]){
        vis[node] = 1;
        
        for(auto nbr: adj[node]){
            int v = nbr.first;
            if(!vis[v]){
                topoUsingDfs(v,st,vis,adj);
            }
        }
        st.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        // 1. topological sort
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0; i<N; i++){
            if(!vis[i]){
                topoUsingDfs(i, st, vis, adj);
            }
        }
        
        // 2. calc shortest dist by relaxation of the node.
        vector<int> dist(N, INT_MAX);
        dist[0] = 0; //src node
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto nbr: adj[node]){
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[node] != INT_MAX && dist[node] + wt < dist[v]){ // relaxation of nodes
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i=0; i<N; i++){  // for unreachable node from the vertex -> return -1
            if(dist[i]==INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};