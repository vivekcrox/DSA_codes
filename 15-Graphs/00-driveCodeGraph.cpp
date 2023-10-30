#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction){
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
    
    Graph g;
    // // Undirected input
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // cout<<endl;
    // g.printAdjList();

    // Directed input
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    cout<<endl;
    g.printAdjList();

    return 0;
}