class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // vector<int> dist(V, INT_MAX);
        // dist[S] = 0;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pq.push({0, S});
        // while(!pq.empty()){
        //     int dis = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
            
        //     for(auto it: adj[node]){
        //         int edgeWgt =  it[1];
        //         int adjNode = it[0];
                
        //         if( dis + edgeWgt < dist[adjNode]){
        //             dist[adjNode] = dis + edgeWgt;
        //             pq.push({dist[adjNode], adjNode});
        //         }
        //     }
        // }
        // return dist;
        
        // 2. Using set
        
        set<pair<int,int>> st;
        vector<int> dist(V, INT_MAX);
        
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                
                if(dis + wt < dist[adjNode]){
                    //erase if it already exist and have large dist
                    if(dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = dis + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};