
To calculate all pair shortest path : we use Floyd-Warshall's Algorithm.

for All Pair Shortest Path(APSP) : we can call dijkstra's Algorithm for all the nodes , time taken doing so : V*(E LogV) : in worst case , E ~ V^2 , so O(v^3 LogV)

If we use Bellman-Ford Algorithm : 
Time taken doing so : V*(E*V) : in worst case E ~ V^2 : O(V*(V*V^2)) ~ O(v^4)  

If we use Floyd-Warshall's Algorithm : O(V^3)

Floyd-Warshall's Algorithm is an "Exhaustive Based Solution".
Floyd-Warshall's Algorithm is a "DP based solution"

Floyd-Warshall works even if the graph has negative weight edge , also because it is an exhaustive based solution (dp based algorithm) , if there is a 'negative weight cycle' Floyd_warshall can detect it.




Working of Floyd-Warshall's Algorithm 

Let's say we have two nodes in the graph (i and j) , and we want to find the shortest path between (i and j) , now we want to find out the length of the shortest path between (i and j).

Brute-force method of doing this would be : explore all the paths between (i and j) , and the shortest path will be our answer.   
Now the way we explore all the paths between (i and j) will determine time taken by the algorithm to find the shortest path.

There is a possibility that : i and j are connected together.
There is also a possibility that : there is one intermediate vertex between (i and j)
There might be also a possibility that : there are 2 intermediate vertices between (i and j)
and so on.. there might be (V-2) vertices between (i and j).

So , for the nodes ( i and j) , for which we have to calculate the shortest path , Fist of all we will figure out : 
--> What is the length of shortest path between (i and j) , such that along that path : there are exactly "Zero nodes" in-between.

--> then , What is the length of shortest path between (i and j) , such that along that path : there are exactly "One nodes" in-between.

--> then , What is the length of shortest path between (i and j) , such that along that path : there are exactly "Two nodes" in-between.

--> then , What is the length of shortest path between (i and j) , such that along that path : there are exactly "Three nodes" in-between.

--> then , What is the length of shortest path between (i and j) , such that along that path : there are exactly "Four nodes" in-between.

--> then , What is the length of shortest path between (i and j) , such that along that path : there are exactly "(V-2) nodes" in-between. (V-2) because the other 2 nodes are (i and j)

After calculating all the answers from above (and it is very much possible that some answers might not exists , for example what if there are no exactly K nodes between (i and j)), we will take minimum of all the answers.
This is brute force way of calculating the shortest path between node (i and j).



To overcome this brute force : what Floyd-Warshall says : 
Let's say we have 2 nodes (i and j) in the graph , and we want to find the shortest between them. 

As Per Floyd-Warshall's Algorithm : Here we are considering , Labelling of the nodes are 1-based not 0-based.
--> First of all find the shortest path between (i and j) such that along that path there are (atMost 0 node (<= 0)).

--> Now , find the shortest path between (i and j) such that along that path there are (atMost 1 node (<= 1)).

--> Now , find the shortest path between (i and j) such that along that path there are (atMost 1 node (<= 1)) , either exactly 0 nodes in-between or 1 node in-between and if there is "exactly one" node in-between then that node must be with label : 1.

--> Now , find the shortest path between (i and j) such that along that path there are (atMost 2 node (<= 2)), either exactly 0 nodes in-between or 1 node in-between or exactly 2 nodes in between and if there is "exactly two" nodes in-between then that node must be from the set of nodes {1,2}.

--> Now , find the shortest path between (i and j) such that along that path there are (atMost 3 node (<= 3)), and the "at-most 3 nodes" can only be form from the unique combination of nodes from the set of nodes (1,2,3).

--> Now , find the shortest path between (i and j) such that along that path there are (atMost 4 node (<= 4)), and the "at-most 4 nodes" can only be form from the unique combination of nodes from the set of nodes (1,2,3,4).

and so on...

--> Now , find the shortest path between (i and j) such that along that path there are (atMost V node (<= V)), and the "at-most V nodes" can only be form from the unique combination of nodes from the set of nodes (1,2,3,4,.....V). It is obvious that the shortest path from (i and j) will only have (V-2) nodes along the way , but since we do not know the exact value of i and j , we wrote in-general for V nodes along the way.
Also , we can think it like what is the path between (i and j) goes through "Vth" node , so to consider "Vth" node , we need to do the calculation for atMost V nodes. 

In every iteration we are introducing a new node.

At the end , take minimum of all these , that would be the answer of shortest path between node (i and j).


As FLoyd-Warshal is a DP- based Exhaustive Solution.

We need to define states , parameters , transition for Floyd-Warshall's Algorithm.

// first of all we need to define the pair [i,j] for which we are calculating the shortes path , then we need parameter for the range of nodes (at-most k (<= k))

so , there should be 3 paramters in the state of dp ,
dp[i][j][k] : (i , j are the end nodes for which we are trying to calculate the shortest path) , k is the at-most limit for which shortest path will be there in dp[i][j][k]


State :
dp[i][j][k] states the length of the shortest path between node i and node j such that along that path there are at-Most k nodes and those k nodes are from {1,2,3,4,....,k) i.e.(and the maximum labelled node is also <= k)


Transition for dp[i][j][k]:

when we are doing calculation for dp[i][j][k] , by that time , we have already calculated dp[i][j][0...(k-1)] i.e. dp[i][j][0] , dp[i][j][1] , dp[i][j][2] .... , dp[i][j][k-1]

now the transition for dp[i][j][k] : min(dp[i][j][k-1] , min(all the path between [i,j] in which kth node is an intermediate node)).

minimum of all(dp[i][j][0] , dp[i][j][1] , dp[i][j][2] .... , dp[i][j][k-1]) is stored in dp[i][j][k-1]

In the calculation of dp[i][j][k] , there are 2 cases : either use node k OR don't use node k

Case 1 : The shortest path goes through (node k) : dp[i][j][k] means find the length of the shortest path between (i and j) such that along that path we are using at-most k nodes and those k nodes can be (1,2,3,4...k) i.e. the shortest path goes through (node k) and that shortest path length going through node k would be : shortest path length from [i to k] + shortest path length from [k to j] , and we know for sure , k would never be used in the shortest path from [i to k] and k would never be used in the shortest path from [k to j]

so , shortest path from [i to k] is : dp[i][k][k-1] 
     shortest path from [k to j] is : dp[k][j][k-1]

and dp[i][j][k] = dp[i][k][k-1] + dp[k][j][k-1]

Case 2 : The shortest path does not goes through node k : dp[i][j][k-1]

so , dp[i][j][k] would be minimum of both case 1 and case 2

dp[i][j][k] = min(dp[i][k][k-1] + dp[k][j][k-1]  ,  dp[i][j][k-1]) 



In dp[i][k][k-1] + dp[k][j][k-1] , in both the terms we used [k-1] because it is obvious that in the shortest path from [i to k] , k cannot appear in between


for the dimension of dp[][][] : 1 <= i <= n : exactly n values of i are possible
                                1 <= j <= n : exactly n values of j are possible
                                0 <= k <= n : exactly (n+1) values of j are possible

as vectors follows 0-based indexing and if our nodes are labelled from [1 to n]
then the dimensions of the dp vector would be [n+1][n+1][n+1]

dimensions of DP : dp[n+1][n+1][n+1] : for i and j , we would not use 0th index 

for 3D-vector : every element of the 3D-vector is a 2D-vector in itself.

dp[i][j][0] is the base case : if there exists a direct edge between [i,j] , use it 
                               if there does not exist any direct edge between [i,j] , use INFINITY 

dp[i][j][n] stores the final answer.

Time : O(V^3)
Space : O(V^3)

Space can be optimised , we can use 2D-vector instead of 3D-vector , ad dp[i][j][k] only depends upon dp[][][k-1] i.e. (kth matrix depends upon (k-1)th matrix) , so it can be optimised into 2D-vector , we can use "two" 2-D vector , one for "k" and other for "k-1".

Space can further be optimised into "single" 2D-vector , store the result in the same 2D-vector.

One 2D-vector is enough because , 
dp[i][j][k] = min( dp[i][j][k-1] , dp[i][k][k-1] + dp[k][j][k-1]) ;

for understanding , if we ignore the kth dimension

dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]) ;

in calculation of dp[i][j] , the allready stored value at dp[i][j] is dp[i][j][k-1]
and one can argue , what if dp[i][k] and dp[k][j] gets updated before using it in the calculation of dp[i][j] , well dp[i][k] and dp[k][j] is not going to trouble because we are calclating the shortest path between [i,j] when k is an intermediate node along the path , and for the shortest path from [i to k] , k cannot be an intermediate vertex , also for the shortest path from [k to j] ,k cannot be an intermediate vertex.
so , for dp[i][k][k] would still be dp[i][k][k-1] because k cannot be an intermediate node in the shortest path from k to j
also , for dp[k][j][k] would still be dp[k][j][k-1] because k cannot be an intermediate node in the shortest path from k to j.