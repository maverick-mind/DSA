// Implementation of weighted Graph using Map , when labels are non-integers and when edges are weighted
// Implementation of weighted Graph : when edges are weighted 

/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v and w where u, v are edge endpoints and w is weight of the edge.

input :

5 6
A B 7
A C 1
B D 2
C D 9
C E 6
D E 5

*/

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n ; // number of vertices 
    int m ; // number of edges 

    cin >> n >> m ;

    map<char , vector<pair<char , int>>> adj ; // <vertex , vector < pair<neighbour , weight>>
 
    for(int i = 0 ; i < m ; i++)
    {
        char u , v ; // u and v are neighbours 
        int weight ; // weight of the edge between vertices : u and v 
        cin >> u >> v >> weight ;

        adj[u].push_back({v , weight}); // adj[u].push_back(make_pair(v , weight)); 
        adj[v].push_back({u , weight}); // comment this out if the graph is directed 
        
    }

    for(auto [nodeLabel , neighbourList] : adj)
    {
        cout << "neighbour of vertex " << nodeLabel << " with edge weight are : ";
        
        for(auto [neighbour , edgeWeight] : neighbourList)
        {
            cout<<"("<<neighbour<<" , "<<edgeWeight<<") ";
        }cout<<endl; 
    }



 
 
    return 0 ;
}
