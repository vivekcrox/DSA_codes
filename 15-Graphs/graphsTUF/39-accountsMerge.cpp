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
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 1. ["mail1" -> 0 ,"mail2" -> 1.....]
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){ //starts after name index.
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) // if mail not present
                    mapMailNode[mail] = i;
                else
                    ds.unionBySize(i, mapMailNode[mail]);  //map curr 'i' with already present mail 'i'
            }
        }

        // 2. ultimate_Parent -> ["mail", "mail"...]
        vector<string> mergedMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        // 3. [['name','mail'....], ['name','mail'....],.....]
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) // no mail corresponding to that index or has been merged.
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);   //storing name then merged mails.
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};