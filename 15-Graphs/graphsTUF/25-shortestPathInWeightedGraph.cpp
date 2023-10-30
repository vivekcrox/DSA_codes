class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
        vector<int> dist(n+1, INT_MAX), parent(n+1);
        for(int i=1; i<=n; i++)
            parent[i] = i;
        dist[1] = 0;  //src node;
        pq.push({0,1});  // {dist, node}
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
        
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dis+wt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int node = n;
        // O(n)
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};