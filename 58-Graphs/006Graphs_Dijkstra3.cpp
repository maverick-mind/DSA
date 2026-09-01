// Generate the shortest path in the Dijkstra's Algorithm


/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/


#include<bits/stdc++.h>
using namespace std;

void printPath(vector<int> & parent ,int i)
{
    deque<int> dqPath ;
    dqPath.push_front(i) ;
    while(parent[i] != -1)
    {
        dqPath.push_front(parent[i]) ;
        i = parent[i] ;
    }

    for(auto it : dqPath)
    {
        cout<<it<<" ";
    }
}
 
 
int main() 
{

    int n ; // number of nodes 
    int m ; // number of edges 

    cin >> n >> m ;
    
    vector<vector<pair<int , int>>> adj(n) ;

    for (int i = 0; i < m; i++)
    {
        int u , v ; // vertices u and v are neighbour in the weighted graph
        int edgeWeight ;

        cin >> u >> v >> edgeWeight ;

        adj[u].push_back({v , edgeWeight}) ;
        adj[v].push_back({u , edgeWeight}) ;
    }

    vector<bool> explored(n , false) ;

    vector<int> distMap(n , INT_MAX) ; // initially all the nodes are at infinite distance from the source node 

    int src = 0;
    distMap[src] = 0 ;

    set<pair<int , int>> unexplored ; // <tentative distance , vertex>

    

    // to "generate" the shortest path using dijkstra's algorithm , we need to track the parent of each node
    vector<int> parent(n) ;
    parent[src] = -1 ;


    unexplored.insert({distMap[src] , src}) ;

    while(! unexplored.empty())
    {
        auto [dist , currNode] = *(unexplored.begin()) ;

        // travel to all the neighbour of currNode which are unexplored 
        for(auto [ngb , edgeWeight] : adj[currNode])
        {
            if(explored[ngb] == false)
            {
                if(distMap[ngb] > distMap[currNode] + edgeWeight) 
                {                                                 
                    // relax the tensed edge
                    unexplored.erase({distMap[ngb] , ngb}) ;
                    distMap[ngb] = distMap[currNode] + edgeWeight ;

                    unexplored.insert({distMap[ngb] , ngb}) ;

                    parent[ngb] = currNode ; // since we are able to find a better path to ngb via currNode , we can say that currNode is the parent of ngb in the shortest path tree
                }
            }
        }
        // now the currNode is explored , remove it from the unexplored seat and mark is explored 
        unexplored.erase({distMap[currNode] , currNode}) ;
        explored[currNode] = true ;
    }
    

    for (int i = 0; i < n; i++)
    {
        cout<<"dist ("<<i<<") : "<<distMap[i]<<endl;
    }


    for (int i = 0; i < n; i++)
    {
        cout<<"shortest path from source ("<<src<<") to node ("<<i<<") : ";
        printPath(parent , i) ;
        cout<<endl;
    }
 
 
 
    return 0 ;
}