class Solution {
public:
        // 1. Using Floyd Warshall Algo.
        // vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // for(auto it: edges){
        //     dist[it[0]][it[1]] = it[2];
        //     dist[it[1]][it[0]] = it[2];
        // }

        // for(int i=0; i<n; i++)
        //     dist[i][i] = 0;
        
        // for(int via=0; via<n; via++){
        //     for(int i=0; i<n; i++){
        //         for(int j=0; j<n; j++){
        //             if(dist[i][via]!=INT_MAX && dist[via][j]!=INT_MAX){
        //                 dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
        //             }
        //         }
        //     }
        // }

        // int cntCity = n; // 
        // int cityNo = -1;
        // for(int city=0; city<n; city++){
        //     int cnt = 0;
        //     for(int adjCity=0; adjCity<n; adjCity++){
        //         if(dist[city][adjCity] <= distanceThreshold)
        //             cnt++;
        //     }

        //     if(cnt <= cntCity){
        //         cntCity = cnt;
        //         cityNo = city;
        //     }
        // }
        // return cityNo;

        // 2. Using Dijkstra's Algo
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        for(int i=0;i<n;i++){
            pq.push({0,i});
            while(!pq.empty()){
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    if(it.second+dis<dist[i][it.first]){
                        dist[i][it.first]=it.second+dis;
                        pq.push({dist[i][it.first],it.first});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    dist[i][j]=0;
            }
        }
        int ans=n;
        int city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++) {
                    if(dist[i][j]<=distanceThreshold)
                        cnt++;
            }
                if(cnt<=ans){
                    ans=cnt;
                    city=i;
                }
            }
        return city;
    }
};