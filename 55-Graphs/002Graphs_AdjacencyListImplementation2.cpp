// Implementation of graph using vector<set<>> : if we want the neighbour of a vertex to be in sorted order 

/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (0 <= u, v < n) where u, v are edge endpoints .

input :

5 6
0 1
0 2
1 3
2 3
2 4
3 4

*/

#include<bits/stdc++.h>
using namespace std;
 
// total space required to maintain adjacency list of undirected graph : |V| + 2 * |E| 

//       (n-1)
// |V| + Σ  (degree of i)
//       i = 0
// this is same as 
// |V| due to size of vector + (2 * |E|) because informatin about each edge is present in 2 neighbour list 

// Σ degree = 2 * |E| , this property is called as "Hand-shaking Lemma" , this means every edge contributes 2 times in the degree 


// sum of all the sizes of neighbour list is same as summation of sum of degrees of all the nodes from 0 to n - 1 

// but , since each index of outer vector of size |V| can store one neighbour on that index , so size would be just : 2E , but it is not a right way to write this , because consider a graph of size |V| , and it has 0 edges E , so we cannot say , we are using 2 * E = 2 * 0 , i.e. 0 size , we are still using |V| size to store all the vertices.



// for directed graph that contains |V| vertices and |E| edges , 
// total space required to maintain it's adjacency list for directed graph would be : 
// |V| + |E| , at each index , we store successors of that index only , and each edge can have a single successor , thus sum of all the successor of all the edges would be equal to sum of all the edges. we can also say that , information of each edge is inside only one neighbour list , so total space : |V| + |E| 

int main() 
{
    int n ; // number of vertices 
    int m ; // number of edges 
    cin >> n >> m ; 

    vector<set<int>> adj(n) ; // each index of the vector store set of neighbours of node with value as : index 

    for(int i = 0 ; i < m ; i++)
    {
        int u ; // u and v are connected to each other through an edge 
        int v ; 

        cin >> u >> v ; 

        adj[u].insert(v) ;
        adj[v].insert(u) ; // comment this out if the graph is directed 
    }
 
    
    for(int i = 0 ; i < n ; i++)
    {
        set<int> & neighbourList = adj[i] ;

        cout << "neighbour of vertex " << i <<" : ";

        // auto can be used only in place of primitive datatypes like int , char , long long , double , float. we cannot use auto for storing something of set<int> datatype  
        for(auto & nghbr : neighbourList) // or const int & nghbr : neighbourList
        {
            cout << nghbr << " " ;
        }cout<<endl ;
        
        /* 
        // With a set<int>, the iterator gives you a const int&, not an int&. Therefore, this:
        for(int & nghbr : neighbourList)// for(const int & nghbr : neighbourList) will work
        {
            cout << nghbr << " " ;
        }cout<<endl
        // will not compile.

        // Think of a set as: you can read its elements, but you cannot modify an existing element. so use const int datatype if you are using refrence & , instead of just using int & , if refrence is not used , we can use int nghbr : adj[i]
        */ 
    }
    cout << endl ;

    for(int i = 0 ; i < n ; i++)
    {
        set<int> & neighbourList = adj[i] ;

        cout << "neighbour of vertex " << i <<" : ";

        // auto can be used only in place of primitive datatypes like int , char , long long , double , float. we cannot use auto for storing something of set<int> datatype  

        for(int nghbr : neighbourList) // we are making copy of element in set neighbourList
        {
            cout << nghbr << " " ;
        }cout<<endl ;
        
    }
 
    return 0 ;
}


