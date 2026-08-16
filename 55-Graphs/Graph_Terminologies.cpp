/*
--Walk : A walk in a graph is a "sequence of vertices" such that any two vertices adjacent in the vertex sequence are also adjacent in the graph.

--CLOSED WALk , we saay that a walk is "closed" as it starts and ends at the "same graph vertex".


--PATH : A path in a graph is a "walk" in which we visit each vertex of the graph "AT MOST ONCE(<=1)".
Nodes(vertices) don't repeat in path , but they can repeat in a walk.   
--Every path is a walk but every walk is not a path. 


--Cycle : A cycle in a graph is a "closed walk(starting and ending is at the same node)" in which we traverse each graph edge at most once(<= 1). 
EVERY "cycle" is a "closed walk" , but not every "closed walk" is a "cycle".

A graph "with any number of cycle" is also known as an "cyclic graph".


A graph "without any cycle" is also known as an "acyclic graph".

*/



/*
--CONNECTED_GRAPH : A graph is connected graph if there "exists a path" between "each pair" of graph vertices.

--If a graph is connected graph , then we can say that it has exactly 1 component. 

A graph which is not connected is also known as "Disconnected Graph". --> more than 1 component


--Strongly Connnected Graph : A strongly connected graph is a concept specifically for a directed graph.

A directed graph is strongly connected if:

--> For every pair of vertices u and v, there is a directed path from u to v AND from v to u.

A directed graph is "strongly-connected graph" if there "exists a directed path" between each pair of vertices in the graph. 


--KOSARAJU ALGORITHM : is used to find : number of strongly connected components in a directed graph. 


-- A directed graph is "weakly-connected graph" if there "exists an undirected path" between each pair of vertices in the graph. 



--SUB-Graph : A Sub-Graph of a graph G = {V , E} is a graph G' = {V' , E'} such that V' and E' are subsets of V and E respectively. 


A "proper sub-graph" of a graph is a sub-graph which is the graph itself. 


*/

/*
--COMPONENT : A component of a graph is a sub-graph which is "maximally connected". 

A graph that has multiple components is a disconnected graph 
*/


/*
Every tree is a graph but every graph is not a tree.

TREE : Acyclic 
       connected / path between any 2 vertices.
       each node has exaclty one parent except root node. 


Directed Acyclic Graph : Such a graph , which is "acyclic" and not "tree" is called Directed Acyclic Graph (DAG)


SPANNING TREE : A spanning tree of a connected graph is a sub-graph which is a tree and contains all the vertices of the graph.

for a disconnected graph , we can make spanning tree for each component of a graph and the collection of spanning tree is called as spanning forest. 
*/