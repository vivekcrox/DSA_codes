class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr: adj[node]){
                if(dist[node] + 1 < dist[nbr]){
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }
        
        vector<int> ans(N, -1);
        for(int i=0; i<N; i++){
            if(dist[i] != INT_MAX)
                ans[i] = dist[i];
        }
        return ans;
    }
};