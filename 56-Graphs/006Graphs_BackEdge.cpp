
// check if the directed graph contains any directed cycle or not 
// cycle detection in a directed graph

// Back Edge in "DIRECTED GRAPH" / Cycle Detection in "Directed Graph"

/*
Given a "DIRECTED GRAPH" , design an algorithm to check if it contains a "BACK EDGE".

A directed edge U --> V , is said to be a "BACK-EDGE" if there exists a "DIRECTED PATH" from vertex "V" to vertex "U" , and then we can confirm we have cycle in the Graph.
*/

// When you reach node "U" , and it has a neighbour "V" , and neighbour "V" is already VISITED , if somehow we check we have "DIRECTED PATH" from "V" to "U" , then we can confirm the directed path from V to U , then we can say , there is a BACK EDGE from U to V. 

// can we maintain a set to track all the nodes , which have a directed path to currentNode , when we reach the current Node , basically tracking all the nodes on the different function call stack , when we reach the current Node , all those nodes on the function call stack has a directed path to currentNode.



/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/


#include<bits/stdc++.h>
using namespace std;

// time : O(V + E) , not V + 2*E because we hve directed graph , degree in directed graph is number of edges 
bool dfsCycleDetectionInDirectedGraph(vector<set<int>> & adjacencyList , vector<bool> & visited , set<int> & directedPath , int currentNode)
{
    // mark the currentNode as visited 
    visited[currentNode] = true ;


    for(auto & neighbour : adjacencyList[currentNode])
    {
        // if the neighbour is already visited , check if there exxist a directed path between the neighbour and the current Node 
        if(visited[neighbour] == true)
        {
            if(directedPath.find(neighbour) != directedPath.end())
            {   // there is a directed path between the neighbour and the currentNode ,
                // Back-Edge is found , hence cycle exists in the directed graph
                return true ;
            }
        }
        else{ // neighbour is not visited 
            directedPath.insert(currentNode) ;
            if(dfsCycleDetectionInDirectedGraph(adjacencyList , visited , directedPath , neighbour))
            {
                return true ;
            }
            directedPath.erase(currentNode) ; // backtracking 

        }
    }

    // no Back-Edge is found in the directed graph , hence no cycle exists in the directed graph
    return false ;
}
 
 
int main() 
{
    int n ; // number of nodes 
    int m ; // number of directed edges
    
    cin >> n >> m ;

    vector<set<int>> adjacencyList(n) ;

    for(int i = 0 ; i < m ; i++)
    {
        int u ; // source of the directed node
        int v ; // destination of the directed node 

        cin >> u >> v ;

        adjacencyList[u].insert(v) ; 
        // adjacencyList[v].insert(u) ; // comment this out , if the graph is directed 
    }


    vector<bool> visited(n , false) ; // initially no nodes are visited

    set<int> directedPath ; // to store all the nodes , which have directed path to currentNode , when we reach the currentNode

    bool isCycle = false ;

    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == false)
        {
            if(dfsCycleDetectionInDirectedGraph(adjacencyList , visited , directedPath , i))
            {
                isCycle = true ;
                break ;
            }
        }
    }

    if(isCycle)
    {
        cout<<"Cycle present in the Directed graph"<<endl;
    }else{
        cout<<"Cycle is not present in the Directed graph"<<endl;
    }
    
 
    return 0 ;
}

