
If the graph has non-negative edge weights : always use Dijkstra's Algorithm , it is more efficient over Bellman-Ford Algorithm.

Single Source Shortest Path (SSSP) using Bellman Ford Algorithm :
The Bellman Ford Algorithm can solve the SSSP in case the graph contains "negative edge weights". Also it can be used to detect a "negative weight cycle" in a graph.

Disadvantage of Bellman Ford Algorithm : It is a little bit slower than Dijkstra's Algorithm

Dijkstra : O(ELogV) , E can be at max V^2 : O(v^2(logV)) 
Bellman-Ford : O(V^3)

Dijkstra : Greedy 
Bellman-Ford : Exhaustive Algorithm : DP based solution 

Given a weighted Graph of V number of vertices/nodes
There is a "src" node , and a "destination" node 
Now , along the shortest path from "src" to "destination" , along this path "minimum" number of "edges" : 0 (if source and destination are same)
--> If "source" and "destination" are different then minimum number of "edges" from "source" to "destination" : 1 

--> Maximum number of edges along the shortest path between source and destination : (V-1)
--> If the path from source to destination contains edges more than (v-1) edges , then the path contains "cycle" 



For a weighted graph , containing V vertices , the "minimum" number of edges along the shortest path from the "source" to "destination" vertex is 0 and the "maximum" number of edges along the "shortest path" is equal to (V-1).

If however , the number of edges along the "shortest path" between "source" and "destination" vertex exceeds (V-1) , then we can say the "shortest path" between the "source" and "destination" vertex contains a "negative weight cycle".



Bellman-Ford Algorithm : The idea behind the Bellma-Ford Algorithm for solving SSSP for "weighted graph" that contains "V" vertices is to "relax" "all" the "edges" (V-1) times "in any order".

Every edge is relaxed for (V-1) times. 
time : E(V-1) : (E edges) x (each relaxed for (V-1) times) x (time taken for one relaxation).

There will be round of relaxation , and total round of relaxation would be : (V-1)


If we are at ith round of relaxation , then we have to use result of just previous (i-1)th round relaxation , we cannot use the updated result of ith result in further calculation of other edges in ith round. 



Let us say round 1 of relaxation is done , and we get some distances for some vertices , what does it mean logically ?
Round 1 of relaxation means , currently the distances we are getting during round 1 of relaxation , in these relaxation , we are allowing the path with "at most" "one edges".

Round 2 of relaxation means , we can only reach those nodes from "source" , which are "at most" "2 edges away".

Round 3 of relaxation means , we can only reach those nodes from "source" , which are "at most" "2 edges away".

Round (V-1) of relaxation means , we can reach all those nodes from "source" which are "at max" "(V-1) edges away".

and we are doing at max (V-1) rounds of relaxation because ,the shortest path between 2 nodes will have at max (V-1) edges or we can say (V-1) is the maximum number of edges required to reach any node from the "source node".



Can we use "Bellman Ford Algorithm" for "undirected graph" ?
--> only when all the edges of the "undirected graph" are "non-negative". And if all the edges are non-negative , then use Dijkstra's Algorithm because It is more efficient than Bellman-Ford Algorithm.
A negative edge in an undirected graph automatically creates a negative cycle of length 2 (when represented as two directed edges).



Is Bellman-Ford Algorithm Exhaustive ?
Yes , Bellman-Ford Algorithm is Exhaustive , It is a DP-based solution.

For the DP-based Solution : 
State of the Bellman-Ford Algorithm : dp[i][E] states : shortest path or minimum distance(summation of edge weights) from source to vertex : i , such that along the path we can use atMost(E edges)
Here , E(edges) refers to the number of rounds , in Eth round , we can use E number of edges.


dp[i][j] : It is the function that finds the length of shortest path from "source" to vertex "i" , such that along the path , we can use "atMost" "j" edges.

range of i : 0 <= i <= (n-1) , for n nodes from 0 to (n-1)
range of j : 1 <= j <= (n-1) , for (n-1) number of rounds 
or we can say :
range of j : 0 <= j < (n-1) , for (n-1) number of rounds

Every combination of [i and j] is a "unique sub-problem".
Total : n^2 unique sub-problems.

and to solve every sub-problem , we are spending linear time : so total cubic time solution.

dp[i][j] = {min(dp[i][j-1] , min(dp[v][j-1] + w))   , when j != 0 

         = INFINITY , if i != source ,    when j == 0
         = 0 , if i == source , when j == 0}


dp[i][j-1] : (previous round result , which stores shortest path from source to ith vertex , when (j-1) edges are used )

v : v are those predecessor vertices of destination i , which are at (j-1) edge distance from the source 
w : edge weight from node v to destination i 

v and w are not single term , there can be multiple [vi , wi].

dp[i][n-1] : last row contain the final answer for the shortest distance from the source node to the ith node.

at any time , dp[i][j] only depends on (j-1) or we can say (previus round) , so we can optimise the 2-D DP Table into two 1-D DP[]. 

Usually in bottom up , we fill the table row-wise,
Here we are filling the table , column-wise.

Time : O(V^2 * V) : V^2 unique sub-problems * V because (min(dp[v][j-1] + w)) can take linear time in worst-case , if the ith node is connected to all other (V-1) nodes.