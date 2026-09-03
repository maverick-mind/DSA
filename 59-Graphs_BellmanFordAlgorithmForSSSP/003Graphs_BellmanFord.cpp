/*

note : nodes are numbered from 0 to n - 1

bellman-ford's algorithm

e.g.

input :

5 7
0 1 2
0 2 5
1 2 1
1 3 6
1 4 4
2 4 1
4 3 1

output :

0 2 3 5 4

*/


#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{

    int n ; // number of edges 
    int m ; // number of directed edges 

    cin >> n >> m ;

    vector<vector<pair<int , int>>> adj(n) ;// Bellman-Ford is usually implemented using an edge list, rather than an adjacency list, because the algorithm fundamentally says: Relax every edge V - 1 times.

    // adjacency-list implementation still has the same complexity and is completely valid:
    // Time: O(V × E)
    // Space: O(V + E)
    for(int i = 0 ; i < m ; i++)
    {
        int u , v , edgeWeight ;
        cin >> u >> v >> edgeWeight ;

        adj[u].push_back({v , edgeWeight}) ;
        // adj[v].push_back({u , edgeWeight}) ; // comment this out if the graph is directed 
    }

    // to store the result of previous round of edge relaxation , and to store the result of this round after relaxation , we will be using two 1-D vectors 

    vector<int> crDistMap(n , INT_MAX) ; // current round DistMap
    // vector<int> nrDistMap(n , INT_MAX) ; // next round DistMap

    // distance of source node from source node in the current round : 0
    int src = 0 ; 

    crDistMap[src] = 0 ;
    

    // During round i, only paths containing at most i edges are considered.
    for (int i = 1; i <= n-1; i++) // n-1 maximum rounds we are doing ,
    {   // we are doing at max (V-1) rounds of relaxation because ,
        // the shortest path between 2 nodes will have at max (V-1) edges or 
        // we can say (V-1) is the maximum number of edges required to reach any node from the "source node".
        
        vector<int> nrDistMap = crDistMap ; // next round DistMap

        for(int curr = 0 ; curr < n ; curr++)
        {
            if(crDistMap[curr] != INT_MAX)
            { 
                // it means we can go to the neighbour of this ith node
                for(auto [ngb , edgeWeight] : adj[curr])
                {
                    if(crDistMap[ngb] > crDistMap[curr] + edgeWeight)
                    {
                        nrDistMap[ngb] = crDistMap[curr] + edgeWeight ;
                    }
                }
            }
        }
        crDistMap = nrDistMap ;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"dist ("<<i<<") : "<<crDistMap[i]<<endl;
    }
    return 0 ;
}