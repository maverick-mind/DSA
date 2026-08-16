/*
Assume that you are given a graph that contains |V| vertices and |E| edges 

-- Time taken to List all the neighbours of a vertex U : neighbours of U that is : O(degree(U)) 
*/

/*
-- Add an edge between vertex U and V : O(1) in case of vector<vector<>> --> push_back(V) at uth index of vector and push_back u at vth index of vector 

O(log size of set) in case of vector<set<>> , and size of set is proportional to size of U or V 
*/

/*
-- Check if an edge exists between vertex 'U' and vertex 'V' :

in case of vector<vector<>> :
just check either of (U or V) neighbour list and search for other (V or U) in the neighbour list 
In other words : 
solution 1. go to index U and scan the neighbour list to search for V : O(degree(U))
solution 2. go to index V and scan the neighbour list to search for U : O(degree(V))

solution 3. scan the neighbour list where degree or neighbour list is smaller , i.e. : min(O(degree(U)) , O(degree(V))) 
from 1 and 2 , pick the solution , where neighbour list is smaller or we can say degree is smaller than other , and then start looking for other vertex in the neighbour list of vertex whose degree or neighbour list is smaller , i.e. min(O(degree(u)) , O(degree(V)))



in case of vector<set>> 
solution 1 : go to index U and scan the neighbour list to search for V : O(log(degree(U)))
solution 2 : go to index V and scan the neighbour list to search for U : O(log(degree(V)))
solution 3 : scan neighbour list where degree or neighbour list is smaller ,
             i.e. min(O(degree(U)) , degree(V)) , and then start looking for other vertex in the neighbour list of vertex whose degree or neighbour list is smaller 

*/

/*
--Delete an edge between vertex 'U' and 'V' : 

in case of vector<vector<>> : O(degree(U)) + O(degree(V)) , can be optimised , if we maintain 2 pointers simultanously to delete in U and V , 
and it will take time : O( max(degree(U) , degree(V)))

go to the neighbour list of 'U' and delete 'V' : O(degree(U))
go to the neighbour list of 'V' and delete 'U' : O(degree(V))


in case of vector<set<>> : O(log(degree(U))) + O(log(degree(V)))
go to the neighbour list of 'U' and delete 'V' : O(log(degree(U)))
go to the neighbour list of 'V' and delete 'U' : O(log(degree(V)))

*/


/*
When can we not use vector<vector<>> or vector<set<>> to implement a graph , given that we are using adjacency list as the internal representation 

--> what if the nodes of the graph has labels of string value or character value or integers than exceeds the range of valid indices , because if labels on vetrices are string then the (labels of the node) and (indexes of the graph) would not have one to one mapping.

In that case , just use Map (ordered map because every operations in ordered map every operations is logarithmic , also in unordered_map operations can become linear time , in worst case)

Drawbacks of using vector<vector<>> or vector<set<>> :
If label assigned to vertices are : 
--> integers value that exceeds |V| - 1 
--> non - integers value of labels 


*/