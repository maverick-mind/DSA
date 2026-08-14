/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (0 <= u, v < n) where u, v are edge endpoints .

input :

5 6
0 1
0 2
1 3
2 3
2 4
3 4

*/

// vector<vector<>> implementation of a graph

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n ; // number of vertices 
    int m ; // number of edges 
    cin >> n >> m ; 

    vector<vector<int>> adj(n) ; // vector ov vector<int> 


    // vector<int> adj[n] ; // array of vector<int> 

    

    for (int i = 0; i < m; i++)
    {
        // pair<int , int> edge ;
        // cin >> edge.first >> edge.second ; 

        int u , v ; // u , v are edge endpoints 
        cin >> u >> v;

        // there is an edge between u and v , so u and v are neighbours or each other
        // so , in the adjacency neighbour list :
                                     // at uth index --> insert v ,
                                     // at vth index --> insert u 
        adj[u].push_back(v) ;
        adj[v].push_back(u) ; // comment this out if graph is directed 
    }

    for (int i = 0; i < n; i++)
    {
        cout << "neighbours of node " << i << " --> " ; 
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"  ";
        }cout<<endl;
    }
 
    return 0 ;
}