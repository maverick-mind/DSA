
Dijkstra's Algorithm is an iterative algorithm (not recursive algorithm).

As logn as "edge weights" are "non-negaitves" , dijkstra's algorithm is always going to work , if edge weights are "negative" , dijkstra's algorithm may or may not work.

If edge weights are negative , to solve single source shortest path , we will use : Bellman-ford Algorithm.

For a weighted graph , the "Single Source Shortest Path" is "not defined" , if the graph contains "negative weight cycle".

"Negative weight Cycle" : means sum of weight of all the edges in the cycle is "negative" , and to minimise the path distance , the traversal will stuck in this negative weight cycle , because in each extra cycle traversal the path distance/cost will decrease negatively , and it will tends towards negative infinity , so we cannot solve "single source shortest path" for the graph that contains "negative weight cycle".


for negative edge weights : use bellman ford algorithm 
If the graph has "negative weight cycle" , then bellman ford can detect that "negative weight cycle".

Bellman Ford Algorithm is slower than Dijkstra's Algorithm.

Is Dijkstra an exhaustive algorithm : No , because it does not do minimum of all the paths possible from source to a destination. If it would be an exhaustive algorithm then , anywhere within the algorithm recursion or dp should be used.
Dijkstra's Algorithm is a "Greedy Algorithm". 

Dijkstra's Algorithm is used for weighted graph : Single Source Shortest Path Algorithm For weighted Graph 

Dijkstra's Algorithm use : Given a "weighted" graph "source" vertex , design an algorithm to find the length of the "shortest path" from the "source" vertex to all the "other" vertices.

For SSSP , in unweighted graph , shortest path means "minimum number of edges" , so to minimize the number of edges , we used BFS.
In weighted graph , we don't want to minimize the number of edges , we are trying to minimize the "sum of edge weights".

Dijkastra works for both "Directed Graphs" and "UnDirected Graphs" as long as graph is "weighted".

Similarly , BFS works for both "Directed Graphs" and "UnDirected Graphs" as logn as graph is UnWeighted. 



Let's say , we have a source : "src" , and 2 random vertices "U" and "V" such that there exists a "weighted edge" (here we are considering weighted undirected edge)

Let's say , length (sum of all the weighted edge accross shortest path from src to U) of shortest path from "src--U" : dist[U]
also , tentative (known distance to V before considering weighted edge(U,V)) (shortest path across all the path explored so far (the entire graph is not fully explored yet)) length of the shortest path from "src--V" (without including the edge from U-->V) is : dist[V]

if dist[V] > dist[u] + edgeWeight(U--V)
then the edge (U--V) is called as "Tensed Edge" 



Tensed Edge : An edge is tense when the current distances indicate that the edge can improve the distance to it's destination.



Edge Relaxation : Edge relaxation is the process of trying to improve the currently known distance of a vertex by going through another vertex.



dist[U] + weight(U,V) < dist[V]
                ↓
          Edge is tense
                ↓
         Relax the edge
                ↓
         update dist[V]




In Dijkstra's Algorithm : 
In every iteration : 
        There will be set of nodes for which Distances will be finalised.
        There will be set of nodes for which Distances are not finalised yet.


We don't repeatedly scan all finalized nodes. We process the one unprocessed node with the smallest tentative distance each time.



--> Two sets of vertices : At any point, conceptually we have:

1. Finalized vertices : Their shortest distance from src is guaranteed to be correct.
S = {nodes whose shortest distance is finalized}

2. Unfinalized vertices : We have some tentative distances for them, but they aren't guaranteed to be optimal yet : (V - S)


For example:
          4
     A -------- B
     |
   2 |
     |
     C ----1---- D

Starting at A:

Finalized: A = 0

Tentative:
B = 4
C = 2
D = ∞


--> What Dijkstra actually does :
We don't say: "Let's visit all finalized nodes again and look for tense edges."

Instead:

--> Step 1 : Choose the unfinalized vertex having the smallest tentative distance.


Suppose:  B = 4 , C = 2

We choose: C , because : dist[C] = 2 is smallest.

Then we finalize C.

Finalized: A , C


Step 2: Look at C's incident edges

Now we inspect edges coming out of C.

Suppose: C ----1---- D

Current: dist[C] = 2 , dist[D] = ∞

Check whether the edge is tense:
dist[C] + weight(C,D) < dist[D] --> Yes.
    2 + 1 < ∞ 

Therefore: (C,D) is tense , Relax it:
dist[D] = 3

Now : 
Finalized: A = 0 , C = 2

Tentative: D = 3 , B = 4


-->Then repeat

Among the unfinalized nodes: D = 3 , B = 4

Pick: D , Finalize it.

Then inspect D's incident edges and relax any tense edges.

Then: B = 4 is the smallest remaining tentative distance.

Finalize B , And so on.


--> So the algorithm is really

1. Pick the unfinalized node with the smallest tentative distance.

2. Finalize that node.

3. Look at its incident edges.

4. For each incident edge: check whether it is tense.

5. If tense: relax it.

6. Repeat , Eventually, the shortest distance of every reachable vertex becomes finalized.


Intuition for Dijkstra'a Algorithm : 

                 Dijkstra : 

          Tentative distances
                  ↓
      Pick smallest tentative one
                  ↓
          "This one is safe."
                  ↓
             FINALIZE it
                  ↓
       Explore its incident edges
                  ↓
       Find tense/relaxable edges
                  ↓
          Relax those edges
                  ↓
      Improve tentative distances
                  ↓
               Repeat



Dijkstra's Implementation :
To implements the Dijkstra's algorithm , we will maintain two data structures.

--> To keep track of graph vertices that have been explored.
We will use a "Set" for this purpose.

A vertex is marked as explored if it's "shortest distance" from source has been computed and all the "tensed edges" incident on it have been "relaxed"

--> To keep track of graph vertices that have not been explored.
We will use a Min-Heap for this purpose.

Each item inside the Min_heap will be a pair 
        -- tentative shortest distance of vertex from source
        -- label of vertex.

--> To keep track of distances of nodes from the source : use distance Map 