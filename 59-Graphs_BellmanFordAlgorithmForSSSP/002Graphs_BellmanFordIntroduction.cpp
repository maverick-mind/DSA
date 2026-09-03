

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