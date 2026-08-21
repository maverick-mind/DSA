/*
For topological sort , graph must be "directed" and "acyclic"

Topological Sorting of a "directed acyclic graph" or DAG is a linear ordering of it's vertices such that for each directed edge from vertex "U" to vertex "V" in the graph , "U" comes before "V" in the linear ordering.


A topological sort (or topological ordering) is a way of arranging the vertices of a Directed Acyclic Graph (DAG) so that for every directed edge u → v, vertex u appears before v in the ordering.

A topological sort only exists if the graph has no cycles (i.e., it is a DAG).

--> Works only on Directed Acyclic Graphs (DAGs).
--> Ensures every dependency comes before the task that depends on it.
--> Can be found in O(V + E) time using either Kahn's algorithm or DFS.
*/

// There can be multiple ordering of vertices in topological sort for the same directed acyclic graph 
// pick any edge from "U" to "V , U --> V 
// U must comes before in ordering than V in the topological sort.

// In topological sort , start from the node , whose "INDEGREE" IS  , there must be no incoming edges to the source vertex.
// There can be multiple starting points , if there are multiple nodes with in-degree : 0
// A DAG will always have atleast "ONE" NODE with 0-indegree.



/*
BFS-IMPLEMENTATION (Kahn's Algorithm) :

-- maintain a HashMap to store a mapping between vertices and their in-degrees.
-- initially , push all the nodes into the queue , whose in-degree is 0.

To perform Topological sorting of a DAG using BFS algorithm , we will maintain 
-- A "QUEUE" to track nodes whose dependencies have been resolved i.e. in-degree is 0
-- A "HASHMAP" to store a mapping between vertices and their in-degree.  

*/

/*

Given a directed graph do its topological sorting
-- all the edges are directed edges.
input :

8 14

0 1
0 2
0 3
1 3
1 4
3 2
3 4
3 5
3 6
3 7
4 6
5 2
6 7
7 5

output :

0 1 3 4 6 7 5 2

*/

#include<bits/stdc++.h>
using namespace std;

void bfsKahn_Algorithm(vector<vector<int>> & adjacencyList , unordered_map<int , int> & mpInDegree)
{
    queue<int> que ; // insert all the nodes in the queue whose dependency is 0 

    for(auto [node , inDegree] : mpInDegree)
    {
        // cout<<node<<" , "<<inDegree<<endl;
        if(inDegree == 0)
        {
            que.push(node) ;
        }
    }

    while(! que.empty())
    {
        int nonDependentNode = que.front() ;
        que.pop() ;

        cout << nonDependentNode << " " ;
        // as nonDependentNode is processed now , go to all the neighbours and reduce their dependency by 1 , and among all those neighbours , based on new dependencies , push all the neighbours with 0-dependency into the queue in any order.
        
        for(int ngb : adjacencyList[nonDependentNode])
        {
            mpInDegree[ngb]-- ;
            
            if(mpInDegree[ngb] == 0)
            {
                que.push(ngb);
            }
        }
    }
}
 
 
int main() 
{
    int n ; // number of vertices 
    int m ; // number of directed edges 

    cin >> n >> m ;

    vector<vector<int>> adjacencyList(n) ;
    unordered_map<int , int> mpInDegree ; // <node , indegree>
    
    for (int i = 0; i < m; i++)
    {
        int u ; // source node 
        int v ; // destination node 

        cin >> u >> v ;

        adjacencyList[u].push_back(v) ;
        // adjacencyList[v].push_back(u) ; // comment this out if the graph is directed 

        if(mpInDegree.find(u) == mpInDegree.end()) // if a node has 0 indegree 
        { // we still need to track them 
            mpInDegree[u] = 0 ; //  
        }

        mpInDegree[v]++ ;
    }

    bfsKahn_Algorithm(adjacencyList , mpInDegree) ;
    
    // cout << "hi" << endl ;
 
    return 0 ;
}