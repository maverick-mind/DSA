// Detected cycle in directed-simple graph

// If you try to go to a vertex that is already visted , it is not the necessary condition for a graph to have cycle. 
// for example :  0 -- 1 , visit 0 and then move to it's neighbour 1 , now neighbour of 1 (i.e. 0) is already visited , but the graph does not have cycle , so the idea of detecting cycle hased on already visited vertex is not the necessary condition for a graph to have cycle

// BACK EDGES : If there is a Back Edge while traversing tree in either DFS or BFS , then the graph contain cycle.

/*
If I arive at node "u" and "u" has a neighbour "v" , and "v" is already visited and "v" is not the parent of "u" in the DFS TREE , then it's a backedge and cycle is found.
*/

/*
AT any point , we need 2 things to maintain in the DFS-TREE implementation for cycle detection 
-- Parent 
-- set of visited nodes
*/



/*

Given an undirected graph, check if there exists a cycle or not.

	e.g.

	3 3

	0 1
	0 2
	1 2

*/

// HW : DETECT cycle in graph using BFS 
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
    }

    return adjacencyList ; 
}

// time : O(V + 2E)
// space : O(2V) due to fxn call stack and visited vector
bool dfsGraphCycleCheck(const vector<set<int>> & adjacencyList , vector<bool> & visited , int currentNode , int parentNode)
{
    // base case 
    if(visited[currentNode] == true )
    {
      return false;
    }

    // recurrence relation 

    visited[currentNode] = true ; // mark the current node as visited by making boolean true
    cout<<currentNode<<" ";
    set<int> neighbourList = adjacencyList[currentNode] ; // equivalent to all the children of a tree

   for(const int & neighbour : neighbourList) // from currentNode , iterate over all the choices
   {                                          // of the neighbour , from each neighbour , 
                                              // we will go further for dfs

       if(visited[neighbour] == true and neighbour != parentNode) // BACK EDGE found 
       {
        return true ; // graph contain cycle 
       }
       bool isCycle = dfsGraphCycleCheck(adjacencyList , visited , neighbour , currentNode) ;
       if(isCycle == true)
       {
            return true ;
       }
   }

   return false ; // no cycle found in the component of currentNode
}


int main() 
{

    vector<set<int>> adjacencyList = buildGraph() ;
    cout<<endl;

    int n = adjacencyList.size() ;

    vector<bool> visitedNodes(n , false) ; 
    // int sourceVertex = 0 ; // assume 0 is the source vertex 

    // dfsGraphCycleCheck(adjacencyList , visitedNodes , sourceVertex) ;

    int componentsCount = 0 ;
    bool isCycle = false; // assume no cycle is present

    // time : O(V + 2E)
    // space : O(V)
    for(int i = 0 ; i < n ; i++) // assume the graph is disconnected , if any component contains
    {                            // cycle , the entire graph contain cycle , if no component 
                                 // contains cycle , we can say the graph does not contain cycle
        
        if(visitedNodes[i] == false) // if the node is not visited ,
        {                            // it means it's component is also not visited 
            
            // componentsCount++ ;
            // cout << "component "<<componentsCount<<" : ";

            // use dfs to check if a cycle is present in any component of node i
            if(dfsGraphCycleCheck(adjacencyList , visitedNodes , i , -1)) // -1 is the parent
            {
                // we have found a cycle in the component of node i therefore the given graph is cyclic
                isCycle = true ;
                break ; 
            }
        }
    }cout<<endl;

    if(isCycle == true)
    {
        cout<<"Graph contains cycle"<<endl;
    }
    else // if(isCycle == false)
    {
        cout<<"Graph does not contain cycle"<<endl;
    }
    
    return 0 ;
}