// Single Source Shortest Path for unweighted graph : 

// In undirected graph , shortest path length is defined on number of edges.

// Given a "connected unweighted graph" and "source vertex" , design an algorithm to find the length of the "shortest path" from the "source vertex" to all the other vertices.


// The level of vertices in BFS-TREE of the unweighted graph would be the shortest distance between the source node to all other nodes , considering the source node is on level : 0

// for weighted graph , to find single source shortest path : we have dijkastra's algorithm 
// In weighted graph , for single source shortest path we will try to minimize the edge weights. 



/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

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


#include<bits/stdc++.h>
using namespace std;
 

void bfsSingleShortestSourcePath( vector<vector<int>> & adj , vector<int> & distanceMap , int & source , int n)
{
    vector<bool> visited(n , false) ; // we can also use distanceMap vector and initialise it with -1 , and just check if the distanceMap[node] == -1 , it means it is not visited yet 

    queue<int> que ;

    // insert the current node in the queue and mark it visited 
    que.push(source) ;
    visited[source] = true ;

    int level = 0 ;
    distanceMap[source] = level ;

    while(! que.empty())
    {
        int curr = que.front() ;
        que.pop() ;
        level = distanceMap[curr] ;
        level++ ;
        
        for(auto ngb : adj[curr])
        {
            if(visited[ngb] == false)
            {
                visited[ngb] = true ;
                distanceMap[ngb] = level ;
                que.push(ngb) ;
            }
        }
    }
}
 
int main() 
{
    int n ; // number of vertex 
    int m ; // number of edges 

    cin >> n >> m ;

    vector<vector<int>> adj(n) ;

    for(int i = 0 ; i < m ; i++)
    {
        int u , v ; // u and v are connected through unweighted edge (in this question the edge is undirected too , but the implementation caan also work for the unweighted directed graph)

        cin >> u >> v ;

        adj[u].push_back(v) ; 
        adj[v].push_back(u) ; // comment this out if the graph is directed 

    }

    int source = 0 ;
    vector<int> distanceMap(n , 0) ;

    bfsSingleShortestSourcePath(adj , distanceMap , source , n) ;

    for(int i = 0 ; i < n ; i++)
    {
        cout << i << " : " << distanceMap[i] << endl;
    }


    return 0 ;
}
