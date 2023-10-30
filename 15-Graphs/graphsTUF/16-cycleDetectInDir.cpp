    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int,bool>& visited,
    unordered_map<int,bool>& dfsVisited, vector<int> adj[]) {

		visited[src] = true;
		dfsVisited[src] = true;

		for(auto& nbr: adj[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited,adj);
				if(aageKaAnswer == true)
					return true;
			}
			else if(dfsVisited[nbr] == true) {
				return true;
			}
		}
		//yaha hi galti hoti h 
		dfsVisited[src] = false;
		return false;
	}
    
    bool isCyclic(int V, vector<int> adj[]) {
    //     bool ans = false;
    // 	unordered_map<int, bool> visited;
    // 	unordered_map<int, bool> dfsVisited;
    	
    // 	for(int i=0; i<V; i++) {
    // 		if(!visited[i] ) {
    // 			ans = checkCyclicDirectedGraphUsingDfs(i,visited,dfsVisited, adj);
    // 			if(ans == true)
    // 				break;
    // 		}
    // 	}
    
    // 	if(ans == true) 
    // 		return true;
    // 	else
    // 		return false;
    //     }
    
    
    // 2. Using BFS (Kahn's Algo)
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto nbr: adj[i])
                indegree[nbr]++;
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        // vector<int> topo; // or can maintain cnt var
        int cnt = 0;  
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // topo.push_back(node);
            cnt++;
            
            // remove the indegree for nbr
            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        // if(topo.size()!=V)
        if(cnt != V)
            return true;
            
        return false;
        
    }