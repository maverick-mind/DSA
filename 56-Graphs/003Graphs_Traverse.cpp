// Traversal on Graph , when Graph is Disconnected or Graph has multiple components.

/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

	e.g.

	16 16

	0 2
	0 3
	1 3
	1 4
	2 5
	3 5
	3 6
	4 6

	7 9
	8 9
	9 10
	9 11

	12 13
	12 14
	13 15
	14 15

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
    }

    return adjacencyList ; 
}

void dfsGraphSearch(const vector<set<int>> & adjacencyList , vector<bool> & visited , int currentNode)
{
    // base case --> keep track of the unique nodes so that , we don't end up on the same node again and again 
    if(visited[currentNode] == true) // if the currentNode is allready seen , then return
    {
      return ;
    }

    // recurrence relation 

    visited[currentNode] = true ; // mark the current node as visited by inserting the current node 
    cout<<currentNode<<" ";
    set<int> neighbourList = adjacencyList[currentNode] ; // equivalent to all the children of a tree

   for(const int & neighbour : neighbourList) // from currentNode , iterate over all the choices
   {                                          // of the neighbour , from each neighbour , 
                                              // we will go further for dfs
        dfsGraphSearch(adjacencyList , visited , neighbour) ;
   }

}
 
int main() 
{

    
    vector<set<int>> adjacencyList = buildGraph() ;
    cout<<endl;

    int n = adjacencyList.size() ;

    vector<bool> visitedNodes(n , false) ; 
    // int sourceVertex = 0 ; // assume 0 is the source vertex 

    // dfsGraphSearch(adjacencyList , visitedNodes , sourceVertex) ;

    int componentsCount = 0 ;

    // time : O(V + 2E)
    // space : O(V)
    for(int i = 0 ; i < n ; i++)
    {
        if(visitedNodes[i] == false) // if the node is not visited ,
        {                            // it means it's component is also not visited 
            componentsCount++ ;
            cout << "component "<<componentsCount<<" : ";
            dfsGraphSearch(adjacencyList , reachableNodes , i) ;
            cout<<endl;
        }
    }


    return 0 ;
}

