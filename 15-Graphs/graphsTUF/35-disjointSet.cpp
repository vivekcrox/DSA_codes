#include<iostream>
#include<vector>
using namespace std;

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

int main(){
    
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // if 3 & 7 same or not.
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }
    ds.unionBySize(3,7);
    // if 3 & 7 same or not.
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // // if 3 & 7 same or not.
    // if(ds.findUPar(3) == ds.findUPar(7)){
    //     cout<<"Same"<<endl;
    // }else{
    //     cout<<"Not same"<<endl;
    // }
    // ds.unionByRank(3,7);
    // // if 3 & 7 same or not.
    // if(ds.findUPar(3) == ds.findUPar(7)){
    //     cout<<"Same"<<endl;
    // }else{
    //     cout<<"Not same"<<endl;
    // }

    return 0;
}