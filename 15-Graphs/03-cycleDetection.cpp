class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCyleUndirectedBFS(int src, unordered_map<int,bool>& visited, vector<int> adj[]){
        unordered_map<int,int> parent;
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr: adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 1;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr] && nbr != parent[frontNode]){   //cycle present
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {   //V = 5, E = 5 //adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
        unordered_map<int,bool> visited; 
        
        for(int i=0; i<V; i++){  //for every nodes may there is disconnected components of graph.
            if(!visited[i]){
                bool ans = isCyleUndirectedBFS(i, visited, adj);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};
/*************************************************************/
bool isCyleUndirectedDFS(int src, unordered_map<int,bool>& visited, int parent, vector<int> adj[]){
        visited[src] = true;

		for(auto nbr: adj[src]) {
			if(!visited[nbr]) {
				bool checkAageKaAns = isCyleUndirectedDFS(nbr, visited, src, adj);
				if(checkAageKaAns == true)
					return true;
			}
			else if(visited[nbr] && nbr != parent) {
				//cycle present
				return true;
			}
		}
		return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {   //V = 5, E = 5 //adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
        unordered_map<int,bool> visitedDfs; 
        
        bool ans = 0;
        for(int i=0; i<V; i++){
            if(!visitedDfs[i]){
                ans = isCyleUndirectedDFS(i, visitedDfs, -1, adj);
                if(ans == true){
                    break;
                }
            }
        }
        if(ans)
            return true;
        else
            return false;
    }

/*************************************************************************/
//TLE !!!!!!!!!!!!!!
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int,bool>& visited,
unordered_map<int,bool>& dfsVisited, vector<int> adj[]) {

		visited[src] = true;
		dfsVisited[src] = true;

		for(auto nbr: adj[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited,adj);
				if(aageKaAnswer == true)
					return true;
			}
			else if(visited[nbr] == true && dfsVisited[nbr] == true) {
				return true;
			}
		}
		//yaha hi galti hoti h 
		dfsVisited[src] = false;
		return false;
	}
    
    bool isCyclic(int V, vector<int> adj[]) {
        bool ans = false;
    	unordered_map<int, bool> visited;
    	unordered_map<int, bool> dfsVisited;
    	
    	for(int i=0; i<V; i++) {
    		if(!visited[i] ) {
    			ans = checkCyclicDirectedGraphUsingDfs(i,visited,dfsVisited, adj);
    			if(ans == true)
    				break;
    		}
    	}
    
    	if(ans == true) 
    		return true;
    	else
    		return false;
        }
};