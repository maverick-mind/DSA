// Implementation of Graph using Map , when labels are non-integers 

/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v where u, v are edge endpoints.

input :

5 6
A B
A C
B D
C D
C E
D E

*/

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{

    int n ; // number of vertices 
    int m ; // number of edges 

    cin >> n >> m ; 

    map<char , vector<char>> adj; // map is sorted , unordered map is not sorted 

    for(int i = 0 ; i < m ; i++)
    {
        char u ; // u and v are vertices connected through an edge 
        char v ; 

        cin >> u >> v ; 

        adj[u].push_back(v) ;
        adj[v].push_back(u) ; // comment this out if the graph is directed 
    }

    for(auto [vertex , neighbourList] : adj) // structural binding syntax to extract
    {                                        //  pair<char , vector<char>>  from map 
        cout<<"neighbour of vertex "<<vertex<<" are : ";
        
        auto & neighbour = neighbourList ; 

        for(auto ch : neighbour)
        {
            cout<<ch<<" " ;
        }cout<<endl ;
    }


    
 
 
 
    return 0 ;
}