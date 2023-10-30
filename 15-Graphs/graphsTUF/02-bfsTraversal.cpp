class Solution {
  public:
    // Function to return Breadth First Traversal of given connected graph.
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> visited(V, 0);
        vector<int> bfsAns;
        queue<int> q;
        int src = 0;
        q.push(src);
        visited[src] = 1;
       
        while(!q.empty()){
            int node = q.front();
            q.pop();
           
            bfsAns.push_back(node);
            for(auto nbr: adj[node]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        return bfsAns;
    }
};