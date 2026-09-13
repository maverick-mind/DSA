Disjoint set is a data structure , it is a container which is used to store a collection of sets.
We have multiple dynamic sets (can grow or shrink on runtime) , and we are using disjoint set to store collection of all those disjoint sets , given that intersection of any 2 sets is empty , all the sets must be disjoint to each other.

A disjoint set is a data structure which maintains a collections of dynamic sets {s0 , s1 , s2 , ....} that are pairwise disjoint i.e. for any two sets si and sj in the given collection where i != j , si intersection sj == NULL 

The disjoint set data structure supports three main operations , those include 

--> createSet(x) : to create a new set with a single member x (leader / representative of the set).

--> unionSet(x , y) : to create a set S as a union of sets , Sx and Sy , that contains x and y respectively.

--> findSet(x) : returns the leader or representative of the set that contains the element x.


--Disjoint Set Representation : There are 2 main strategies used to represent the disjoint set data structure.

--> Linked List Representation 

--> Disjoint Forest Representation (faster)
    In the disjoint forest representation , we represent each set in the given set collection using ("ROOTED Tree" data structure i.e. a tree in which each node points to it's 'parent' and each tree node corresponds to a member of the set. Moreover , the root node of the tree corresponding to a given set 'points to itself' and is the "LEADER" or the representative of the set)

--> Operations with Forest Representation
   
    --> createSet(x) : make a tree in which there is only one node to represent "x" and that node will point to itself and that node is leader of this set.
    time : O(1)

    --> findSet(x) : findset(x) means we want the leader of the set in which x exists , 
    to find the leader of the x : go to parent of x , and then to the parent of the parent of x and so on , till the time we have parent of currentNode = currentNode , then we can say , we have found the leader of the set in which x exists.
    time : O(height of the tree containing x)

    --> unionSet(x,y) :
    findSet(x) will return leader of set containing x , assume : K.
    findSet(y) will return leader of set containing y , assume : J. 
    Now for union we have 2 options :
    either set parent of  K as J 
    or set parent of J as K
    time in unionSet(x , y) : O(height of the tree containing x) + O(height of the tree containing y) + constant work for changing leander of the combined union set.

--Disjoint Set Implementation with Forest Representation 
    To implement the disjoint set data structure with the forest representation , we will use a hash table to store a mapping between nodes and their parents.

In out implementation , we are going to assume the total number of nodes are from [1....n] and for map we will use vector of size [n+1] (not use index 0)