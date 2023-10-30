// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     // 1. Adjacency Matrix : worst&Avg-> TC=O(N^2 or V^2); 
//     //* Undirected unweighted graph
    
//     int n;
//     cout<<"Enter the number of nodes: "<<endl;
//     cin>>n;

//     vector<vector<int>> adj(n, vector<int>(n, 0));

//     int e;
//     cout<<"Enter the number of edges: "<<endl;
//     cin>>e;

//     for(int i=0; i<e; i++){
//         int u,v;
//         cin>>u>>v;
//         //mark 1
//         adj[u][v] = 1;     // if weighted then store weight instead of 1.
//         adj[v][u] = 1;
//     }

//     // printing
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout<<adj[i][j] <<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }

/************************************************/
// 2.(i) Adjacency List Unweighted
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<list>
// using namespace std;

// class Graph{
// public:
//     unordered_map<int, list<int> > adjList;

//     void addEdge(int u, int v, bool direction){
//         //dir = 0 -> undirected
//         //dir = 1 -> directed
//         adjList[u].push_back(v);
//         if(direction == 0){
//             //undirected edge
//             adjList[v].push_back(u);
//         }
//     }

//     void printAdjList(){
//         for(auto node: adjList){
//             cout<<node.first<<"-> ";
//             for(auto neighbour: node.second){
//                 cout<< neighbour <<", ";
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){
    
//     Graph g;
//     // // Undirected input
//     // g.addEdge(0,1,0);
//     // g.addEdge(1,2,0);
//     // g.addEdge(0,2,0);
//     // cout<<endl;
//     // g.printAdjList();

//     // Directed input
//     g.addEdge(0,1,1);
//     g.addEdge(1,2,1);
//     g.addEdge(0,2,1);
//     cout<<endl;
//     g.printAdjList();

//     return 0;
// }
/* Generic class*/
// 2.(i) Adjacency List Unweighted
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class Graph{
public:
    unordered_map<T, list<T> > adjList;

    void addEdge(T u, T v, bool direction){
        //dir = 0 -> undirected
        //dir = 1 -> directed
        adjList[u].push_back(v);
        if(direction == 0){
            //undirected edge
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<<node.first<<"-> ";
            for(auto neighbour: node.second){
                cout<< neighbour <<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'c', 0);
    g.printAdjList();

    return 0;
}
/***********************/
// // 2.(ii) Adjacency List weighted
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<list>
// using namespace std;

// class Graph{
// public:
//     unordered_map<int, list<pair<int,int>> > adjList;

//     void addEdge(int u, int v, int weight, bool direction){
//         //dir = 0 -> undirected
//         //dir = 1 -> directed
//         adjList[u].push_back({v, weight});
//         if(direction == 0){
//             //undirected edge
//             adjList[v].push_back({u, weight});
//         }
//     }

//     void printAdjList(){
//         for(auto node: adjList){
//             cout<<node.first<<"-> ";
//             for(auto neighbour: node.second){
//                 cout<< "(" << neighbour.first <<", "<<neighbour.second<<"), ";
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){
    
//     Graph g;
//     // Directed input
//     g.addEdge(0,1,5,1);
//     g.addEdge(1,2,8,1);
//     g.addEdge(0,2,6,1);
//     cout<<endl;
//     g.printAdjList();

//     return 0;
// }