
// Breadth First Search : The key idea behind the BFS algorithm is that , for any vertex "u" in the graph , you have to first visit all of it's neighbour bfore you visit the neighbours of it's neighbours.

/*
BFS Implementation : To implement the BFS algorithm , we will maintain 
--> a queue to keep track of nodes that have been visited but not yet explored 
--> a set(either set , map or vector) to keep track of nodes that has been visited. 
*/

// There can be multiple BFS for a graph.

/*
Internally , the graph built using bfs is known as bfs tree , and it is a spanning tree , bfs tree is a sub-graph, tree , that is acyclic and has all the nodes.
Some edges that exists in the graph but are missing in the bfs-tree are back edges , and presence of back edges means the graph is cyclic 
*/


/*
Implementation of graph search using

  breadth first search   (bfs)

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
 
vector<set<int>> buildGraph()
{

    // build a graph first 
    int n ; // number of vertices
    int m ; // number of edges 

    cin >> n >> m ;

    vector<set<int>> adjacencyList(n) ;

    for(int i = 0 ; i < m ; i++)
    {
        int u , v ; // two ennds of a vertex 
        cin >> u >> v ;

        adjacencyList[u].insert(v);
        adjacencyList[v].insert(u); // comment this out if the graph is directed 
    }

    for(int i = 0 ; i < n ; i++)
    {
        auto & neighbourList = adjacencyList[i] ;

        cout << "neighbour of vertex "<< i <<" : ";
        for(const int & neighbour : neighbourList)
        {
            cout << neighbour <<" " ;
        }cout<<endl; 
    }cout<<endl;

    return adjacencyList ; 
}

// time : |V| (every node is push annd pop exactly one time in queue) + Scanning neighburList of each nodes would be sum of degree of all the nodes , Σ degree(vertices) = 2*(|E|) 
// total time : |V| + 2*|E| ~ O(V + 2E)
// space : |V-1| ((for star graph) , due to queue maximum size possible , if all the nodes are neighbours of source Node) + |V| (due to visited vector) ~ 2* |V| ~ O(V)
void bfsGraphSearch(const vector<set<int>> & adjacencyList , int currentNode)
{
    queue<int> que ;
    int n = adjacencyList.size() ;
    vector<bool> visited(n , false) ; // right now none of the vertices are visited 

    que.push(currentNode) ; // insert the current node on the stack 
    visited[currentNode] = true ;

    while(! que.empty())
    {
        // insert all the unvisited neighbours of currentNode into the queue
        currentNode = que.front() ; 
        auto & neighbourList = adjacencyList[currentNode] ;

        for(auto & neighbour : neighbourList)
        {
            if(visited[neighbour] == false) // because of graph can contain cycle ,
            {   // it is important to keep track of the nodes , that are already visited ,
                // we don't want to insert same node again and again , and get stuck in infinite loop 
                que.push(neighbour) ;
                visited[neighbour] = true ;
            }
        }
        que.pop() ; // remove the currentNode , once all the unvisited neighbours of the current node are inserted
    }

    // all the nodes that can be visited from the source vertex , are tracked in visited vector 
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == true)
        {
            cout << i << " ";
        }
    }cout << endl ;
}

 
int main() 
{
    
    vector<set<int>> adjacencyList = buildGraph() ;

    // set<int> reachableNodes ; 
    int sourceVertex = 0 ; // assume 0 is the source vertex 
  
    bfsGraphSearch(adjacencyList , sourceVertex);
 
    return 0 ;
}