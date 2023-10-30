#include<iostream>
using namespace std;

int main(){
    // 1. Adj Matrix
    //
    int n, e;
    cin>>n>>e;

    vector<vector<int>> adj(n, vector<int>(n,0));
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        
        adj[u][v] = 1;     // In case of weighted graph, store the weight instead of 1.
        adj[v][u] = 1;    // Not in case of Directed Graph
    }

    // 2. Adj List
    // I) Unweighted Graph
    int n, e;
    cin>>n>>e;

    //create list of size n
    vector<int> adj[n];

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // not in case of Directed Graph.
    }

    // II) Weighted graph

    int n, e;
    cin>>n>>e;

    vector<pair<int,int>> adj[n]; 
    for(int i=0; i<e; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // not in case of Directed Graph
    }

    return 0;
}