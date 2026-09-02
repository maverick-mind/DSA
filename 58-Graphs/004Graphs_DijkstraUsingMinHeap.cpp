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

    // vector<bool> explored(n , false) ; // no required assuming graph has non-negative edge weights

    vector<int> distMap(n , INT_MAX) ; // initially all the nodes are at infinite distance from the source node 

    int src = 0;
    distMap[src] = 0 ;

    // set<pair<int , int>> unexplored ; // <tentative distance , vertex>
    // unexplored.insert({distMap[src] , src}) ; 

    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>> pq ;

    pq.push({distMap[src] , src}) ;

    // to "generate" the shortest path using dijkstra's algorithm , we need to track the parent of each node
    vector<int> parent(n) ;
    parent[src] = -1 ;



    while(! pq.empty())
    {
        auto [dist , currNode] = pq.top() ;

        pq.pop() ;

        if(distMap[currNode] < dist) continue ; // because we cannot delete non-top element in heap , there might be possibility that we find a shorter edge distance and we updated the distance map , so in that case remove pq.top() and continue 

        // travel to all the neighbour of currNode which are unexplored 
        for(auto [ngb , edgeWeight] : adj[currNode])
        {
            // if(explored[ngb] == false) // if the ngb is already explored before currNode
            // {            // then distMap[ngb] < distMap[currNode]
                            // in that case ,
                            // (distMap[ngb] > distMap[currNode] + edgeWeight) will return false , so anyways we are not going to change the distMap[ngb] , so no need of explored set/vector if the edge weight is non-negative
                if(distMap[ngb] > distMap[currNode] + edgeWeight) 
                {                                                 
                    // relax the tensed edge
                    // unexplored.erase({distMap[ngb] , ngb}) ; // cannot do this in heap
                    distMap[ngb] = distMap[currNode] + edgeWeight ;

                    // unexplored.insert({distMap[ngb] , ngb}) ;
                    pq.push({distMap[ngb] , ngb}) ;

                    parent[ngb] = currNode ; // since we are able to find a better path to ngb via currNode , we can say that currNode is the parent of ngb in the shortest path tree
                }
            // }
        }
        // now the currNode is explored , remove it from the unexplored seat and mark is explored 
        // unexplored.erase({distMap[currNode] , currNode}) ;
        // explored[currNode] = true ; // no required assuming graph has non-negative edge weights
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