// Basically we have count the number of different components of the disconnected graph.
class Solution {
  public:
    void dfs(int src, vector<int>& visited, vector<int> adj[]){
        visited[src] = 1;
        
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                dfs(nbr, visited, adj);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        //Convert adj matrix to adj list
        vector<int> adjList[V]; // creating an adj. list
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1 && i != j){  //ignore selfNode
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> visited(V, 0);

        // TC -> O(N)+O(N+2E) as for each component partial bfs run which is overall traverse N times.
        for(int i=0; i<V; i++){  
            if(!visited[i]){
                ++count;
                dfs(i, visited, adjList);    // can also use bfs traversal
            }
        }
        return count;
    }
};