class Solution {
  public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, int tin[], int low[], vector<int>& mark, vector<int>adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent)
                continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);      
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{  //updating with tin[it], instead of low[it] as did in bridge finding bcoz we can update with a node coming via deleting node.
                low[node] = min(low[node], tin[it]);  
            }
        }
        if(child > 1 && parent == -1){ //if starting or src node has mutiple child then it is Articulation point.
            mark[node] = 1;
        }
    }
  
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);  // storing A.P as same A.P can be marked by multiple times by its child.
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, mark , adj);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mark[i] == 1)
                ans.push_back(i);
        }
        if(ans.size() == 0) 
            return {-1};
        return ans;
    }
};