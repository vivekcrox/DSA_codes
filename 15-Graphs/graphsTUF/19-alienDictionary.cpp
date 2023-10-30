class Solution{
    public:
    vector<int> topoSort(int V, vector<int>adj[]){
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
        
        vector<int> topo; // or can maintain cnt var
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            // remove the indegree for nbr
            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        return topo;
    }
    
    string findOrder(string dict[], int N, int K){
        vector<int> adj[K];
        for(int i=0; i<N-1; i++){  // compare two words' char one by one.
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());  
            for(int ptr = 0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){   // small -> big -> bigger...etc [mapping of letters]
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto it: topo)
            ans = ans + char(it+'a');
        return ans;
    } 
};