class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        // pq.push({0,0});    // {wt,node}  -> if store only MST sum.
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,-1}});  // {wt,{node,parent}}
        
        vector<int> vis(V,0);
        int sum = 0;
        vector<pair<int,int>> ans;
        
        while(!pq.empty()){
            int node = pq.top().second.first;
            int wt = pq.top().first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(vis[node]==1) // already included in the MST.
                continue;
            
            vis[node] = 1;
            sum += wt;
            ans.push_back({parent, node});
            
            for(auto nbr: adj[node]){
                int v = nbr[0];
                int edWt = nbr[1];
                
                if(!vis[v]){
                    pq.push({edWt, {v, node}});
                }
            }
        }
        for(auto it: ans){ // ignore (-1,0) pair.
            cout<<"("<<it.first<<","<<it.second<<")"<<" , ";
        }cout<<endl;
        return sum;
    }
};