class Solution {
public:
    bool bfsChk(int start, int V, vector<int>adj[], vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                // if the adjacent node is yet not colored
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // is the adj node having the same color
                else if(color[it] == color[node])
                    return false;
            }
        }
        return true;
    }
    
    bool dfsChk(int node, int col, vector<int>&color, vector<int> adj[]){
        color[node] = col;
        
        for(auto it: adj[node]){
            if(color[it] == -1){
                if(dfsChk(it, !col, color, adj)==false) return false;
            }
            else if(color[it] == col)
                return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	           // if(bfsChk(i, V, adj, color)==false)
	           //     return false;
	            if(dfsChk(i, 0, color, adj)==false)
	                return false;
	        }
	    }
	    return true;
	}

};