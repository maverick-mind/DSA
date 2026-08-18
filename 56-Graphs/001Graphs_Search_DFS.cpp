/*
Given a connected graph and a source vertex , design an algorithm to find all the vertices "reachable" from the source vertex. A vertex "v" in the graph is said to be reachable from vertex "u" if there exists a path from vertex "u" to vertex "v" ;
*/

// In tree , we have child and parent relation , in graph we have vertices and their neighbours

// DEPTH FIRST SEARCH (DFS) in Graphs : The key idea behind the DFS algorithms in graph is that for any vertex "u" in the graph , when you visit one of it's "unvisited neighbours" , say "v" then first you visit all the unvisited vertices reachable from "v" before you visit the other "unvisited neighbour" of "u".

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

// In trees , we have child nodes , in graph we have neighbouring vertices 
// In trees , we have no cycles so no need to worry which node is visited and which is not visited. In graph we have cycles , so it is important to track which node is visited and which node is not visited , so that we don't end up again and again on the same node. 


// list all the vertices that can be reached from the source node , here source node is 0
void dfsGraphSearch(const vector<set<int>> & adjacencyList , set<int> & st , int currentNode)
{
    // base case --> keep track of the unique nodes so that , we don't end up on the same node again and again 
    if(st.find(currentNode) != st.end()) // if the currentNode is allready seen , then return
    {
      return ;
    }

    // recurrence relation 

    st.insert(currentNode) ; // mark the current node as visited by inserting the current node 
    set<int> neighbourList = adjacencyList[currentNode] ; // equivalent to all the children of a tree

   for(const int & neighbour : neighbourList) // from currentNode , iterate over all the choices
   {                                          // of the neighbour , from each neighbour , 
                                              // we will go further for dfs
        dfsGraphSearch(adjacencyList , st , neighbour) ;
   }

}
 
int main() 
{

    vector<set<int>> adjacencyList = buildGraph() ;

    set<int> reachableNodes ; 
    int sourceVertex = 0 ; // assume 0 is the source vertex 

    dfsGraphSearch(adjacencyList , reachableNodes , sourceVertex) ;

    for(auto & neighbour : reachableNodes)
    {
        cout<<neighbour<<"  ";
    }cout<<endl;

    return 0 ;
}