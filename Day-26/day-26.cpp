#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited) 
{
    visited[node]=true;
    for(int neighbor:adj[node]) 
    {
        if(!visited[neighbor]) 
        {
            if(dfs(neighbor, node, adj, visited)) 
            {
                return true; 
            }
        }
        else if(neighbor!=parent) 
        {
            return true;
        }
    }
    return false; 
}
bool c1(int V, vector<pair<int, int>> &edges) 
{
    vector<int> adj[V];
    for(auto edge:edges) 
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++) 
    {
        if (!visited[i]) 
        {
            if (dfs(i, -1, adj, visited)) 
            {
                return true; 
            }
        }
    }
    return false; 
}

int main() 
{
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;
    vector<pair<int, int>> edges;
    cout << "Enter the edges (as pairs of vertices):" << endl;
    for(int i=0;i<E;i++) 
    {
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }
    if(c1(V, edges)) 
    {
        cout<<"Output: true (Cycle detected)"<<endl;
    } 
    else 
    {
        cout<<"Output: false (No cycle detected)"<<endl;
    }
    return 0;
}
