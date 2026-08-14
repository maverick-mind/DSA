/*
Graph is a non-linear data structure that can be thought as of collections of nodes(or vertices) and edges 

n : nodes / vertices : |V| (number of nodes or vertices)
generally in graph of n nodes , the labels are either [0 , n-1] or [1 , n]

m : edges/link : |E| (number of edges)

"COMPONENT" in a graph : A component is a group of vertices where every vertex can reach every other vertex through some path, and there is no path connecting this group to another group.


Every tree is a graph but every graph is not a tree because graph can be cyclic but trees are acyclic 

Formally , graph is a pair of sets V and E where V is a non-empty set of vertices and E is a set of edges such that each edge is a pair of vertices.

In a directed graph , each edge is an ordered pair of vertices 

In a weighted graph , each edge is assigned a weight. 

Graph can be of 4 categories : 

            unweighted     weighted 
undirected      1              2
 
directed        3              4 


Applications of Graph : 

1. Social Networking Sites : 
            Users : can be thought as nodes in a graph
            Relationships : can be thought as edge between graph nodes.

2. Map of a City : 
            Checkpoints : can be thought as nodes in a graph 
            Roads : can be thought as edge between graph nodes.
*/


/*
Graph Terminologies : 

-- In an undirected graph , if there exists an edge between 2 vertices then they are said to be "adjacent/neighbour" to each other. 

-- Degree of a vertex/node : In an undirected graph , we define "degree" of a vertex as the number of edges incident on that node.


-- In a directed graph , if there exists a directed edge : u --> v 

then we say that : 
        vertex "u" is "predecessor" of "v"   and   vertex "v" is "successor" of vertex "u"

-- for a directed graph , we define 

"in-degree" : of a vertex as the number of "incoming-edges" on that vertex 
"out-degree" : of a vertex as the number of "outgoing-edges" from that vertex 


In an undirected graph , two or more edges are said to be parallel edges if they are incident on the same two vertices. 

In a directed graph , two or more edges are said to be parallel edges if they have the same tail vertex and the same head vertex. 


In graph theory , we define a loop as an edge that connects a vertex to itself. 
A graph that does not have parallel edges and loops is also known as sinple graph. 

Multi-Graph : A multigraph is a graph that allows multiple edges between the same pair of vertices.

*/


/*
Minimum and maximum number of edges in a Graph : 

The minimum number of edges in a graph is "zero" , and such a graph is known as "empty graph/null graph"

for maximum number of edges in an undirected graph , each vertex of a graph must be connected with every other graph vertex. : n
                        C  
                          2 

-- for an edge , we need 2 vertices : end1 and end2 
--for end1 we have n choices , for end2 we have (n-1) choices 

but , we want unique pair of end1 and end2 , in future end2 may become end1 and end1 may become end2 

so , maximum number of edges in a simple(undirected) graph : n*(n-1)/2


--for simple directed graph : maximum number of edges : n(n-1) or n 
                                                                    p 
                                                                      2 
*/



/*

Graph Representation : 

There are 2 key strategies that can be used to represent the graph data structure 
-- Adjacency List : mostly used 
-- Adjacency Matrix

At high-level , in each of these 2 strategies , we initially implement the graphs using arrays which is indexed by the graph vertices. 

*/


/*
Adjacency List : To represent a graph that contains |V| vertices and |E| edges using adjacency list , we have to create and array is size |V| , such that at each index of the array you store a list of neighbours that correspond to the vertex which has been mapped to that index.

Adjacnecy list can be implemented using :
Implementation of internal view can be done in these 2 ways 
1. Array of linked list 
2. Vector of Vectors : make a vector of |V| size , and at each index of the vector , store a vector , which will keep track of all the neighbours corresponding to the node that was mapped at that index  

Both methods can serve as an implementation of adjacency list , but vector<vector<datatype>> is more convinient than array of linked list.

vector<vector<datatype>> would be jaggered 2d-array OR jaggered 2d-matrix 


--If we want to store all the neighbours of a node in sorted order , we can use vector<set<datatype>> instead of vector<vector<datatype>>

we want to maintain the neighbour list in sorted order because , it is easy to "delete" , "find" a specific neighbour of a node , as it is set , so find operation would be logarithmic , but if it was not set and it was not in sorted order , find operation would be "linear"

if we need to find or delete any neigbhour of a node/vertex , then vector<set<>> would be faster than vector<vector<>>

in vector<set<>> , erase/find in the neighbour list is directly proportional to Log(size of neighbour list)
--and size of neighbour list depends upon the degree of the node/vertex 



-- if the graph is not simple graph , we can use vector of multi-set , instead of vector of set<>



--we can also use hashmap for the graph representation 
1. map<int , set<int>> 
2. map<int , vector<int>> 

key(node/vertex) : value(neighbour list)
for value is hashmap 
--If we want our neighbour list to be sorted : use set<>
--If we don't want to store neighbour list in sorted order : use vector<> 



*/





