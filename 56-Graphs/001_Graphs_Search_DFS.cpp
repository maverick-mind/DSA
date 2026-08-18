/*

Implementation of graph search using

  depth first search   (dfs)

  e.g.

  9 12

  0  1
  0  2
  1  3
  1  4
  2  4
  2  5
  3  6
  4  6
  4  7
  5  7
  6  8
  7  8

*/

#include <iostream>
#include <vector>

using namespace std;

// time : O(V + 2E)
// space: V due to vis[] + V due to fn call stack ~ O(V)

void dfs(int cur, const vector<vector<int> > &adj, vector<bool> &vis)
{

    
    vis[cur] = true; // for |V| nodes , total time : |V| 
    cout << cur << " ";

    for (int ngb : adj[cur]) // accross all the calls , this loop will run for sum of all the degrees of the vertices times , Σ degree(vertices) = 2*(|E|) 
    {
        if (!vis[ngb])
        {
            dfs(ngb, adj, vis);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this out if graph is directed
    }

    int src = 0; // assume 0 is the source vertex
    vector<bool> vis(n, false);

    dfs(src, adj, vis);

    return 0;
}