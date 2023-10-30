class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
	    vis[node] = 1;
	    
	    for(auto nbr: adj[node]){
	        if(!vis[nbr])
	            dfs(nbr, vis, adj, st);
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    stack<int> st;
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i])
	            dfs(i, vis, adj, st);
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};