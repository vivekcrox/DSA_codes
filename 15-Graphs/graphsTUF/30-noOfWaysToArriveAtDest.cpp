class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = int(1e9 + 7);
        
        //edge case
        
        vector<pair<long long,long long>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>> > pq;
        pq.push({0,0});
        
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        
        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto nbr: adj[node]){
                long long v = nbr.first;
                long long wt = nbr.second;
                
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    ways[v] = ways[node];  //ways will same as its prev node where come from.
                    pq.push({dist[v], v});
                }
                else if(dis + wt == dist[v]){
                    ways[v] = (ways[v] + ways[node])%mod; // add ways from other path with same dist.
                }
            }
        }
        return int(ways[n-1] % mod);
    }
};