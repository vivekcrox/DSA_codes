class DisjointSet{
public: 
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);   //n+1 -> so that can handle both 0 and 1 base indexing graph.
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){   // find Ultimate parent of the node.
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // Path Compression -> by storing the parent[node];
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return ;   // already connected to same component.
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{ //when rank same then add to anyone.
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return ;   // already connected to same component.
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{ // in case of rank(u) > rank(v) or equal.
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // As we sorting nodes, i.e 1->2 & no nedd to check 2->1.
        vector<pair<int,pair<int,int>> > edges;
        // O(V+E)
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node,adjNode}});
            }
        }
        DisjointSet ds(V);
        // ElogE
        sort(edges.begin(), edges.end());
        
        int mstWt = 0;
        //E*4*alpha
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};