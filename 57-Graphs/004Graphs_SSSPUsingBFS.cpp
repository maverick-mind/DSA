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


// extent the single source shortest path question , 
// Earlier we were focusing on just shortest length from from source node to all other node.
// Now , we want to print the shortest length from "source node" to a given "destination node".

// Tp print the shortest length path from "source node" to "destination node" , at each node , just store the parent of that node 

vector<int> generateSSSPath(vector<int> & parentMap , int destination)
{
    // from destination we can reach each parent in the heirarchy untill we reach the source node
    int curr = destination ;
    vector<int> path ;
    
    
    path.push_back(curr) ;

    while(parentMap[curr] != -1)
    {
        curr = parentMap[curr] ;
        path.push_back(curr) ;        
    }

    // since we have built the path from destination to source , just reverse the path to get path from source to destination 
    reverse(path.begin() , path.end()) ;

    return path ;
}
 

void bfsSingleShortestSourcePath( vector<vector<int>> & adj , vector<int> & distanceMap , int & source , vector<int> & parentMap , int n)
{
    vector<bool> visited(n , false) ; // we can also use distanceMap vector and initialise it with -1 , and just check if the distanceMap[node] == -1 , it means it is not visited yet 

    queue<int> que ;

    // insert the current node in the queue and mark it visited 
    que.push(source) ;
    visited[source] = true ;

    int distFromSource = 0 ;
    distanceMap[source] = distFromSource ;

    parentMap[source] = -1 ;

    while(! que.empty())
    {
        int curr = que.front() ;
        que.pop() ;
        // distFromSource = distanceMap[curr] ;
        // distFromSource++ ; // shortest distance of all the neighbour of current node from the source = shortest distance of current node from the source + 1 
        
        for(auto ngb : adj[curr])
        {
            if(visited[ngb] == false)
            {
                visited[ngb] = true ;
                que.push(ngb) ;
                // distanceMap[ngb] = distFromSource ;
                distanceMap[ngb] = distanceMap[curr] + 1 ; // since we are visiting ngb through curr it means in the BFS tree , curr is the parent of ngb 

                // parent of ngb is curr node 
                parentMap[ngb] = curr ;
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

    vector<int> parentMap(n) ;

    bfsSingleShortestSourcePath(adj , distanceMap , source , parentMap , n) ;

    cout<<endl<<"Single Source Shortest Path of each node from the source node "<< source <<" : "<< endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << i << " : " << distanceMap[i] << endl;
    }cout<<endl;


    // print shortest path from source to each node in the undirected graph
    
    for(int i = 0 ; i < n ; i++)
    {
        vector<int> path = generateSSSPath(parentMap , i) ;

        cout<<"path ("<<i<<") : ";
        for(int node : path)
        {
            cout << node <<" ";
        }cout << endl ;
    }


    return 0 ;
}
