/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/


#include<bits/stdc++.h>
using namespace std;
 

// space : V + 2*E due to adjacency list + V due to explored vertices + V due to unexplored vertices + V due to distance map , but at any time : explored + unexplored = V vertices , but we are using boolean vector for explored which is of size : V , 
// overall : V + 2*E + V + V + V ~ 4V + 2E when space of adjacency list is considered 

// if adjacency list is not considered 
// space : O(V)

// time : at max , the size of the heap is V (there cannot be multiple entries of a single node) , so if there are always V entries on the set , then every operation on the set is of (logV) time (find , erase , insert operation) , so time spent during 1 relaxation is (logV)
// we can do a maximum of (E) relaxations , every edge will undergo relaxation at most 1 time 
// total time to relax all the edges : E(logV)
int main() 
{
    int n ; // number of nodes / vertices 
    int m ; // number of edges (all edges are weighted)
    
    cin >> n >> m ;

    vector<vector<pair<int , int>>> adj (n) ;

    for (int i = 0; i < m; i++)
    {
        int ngb1 , ngb2 , edgeWeight ;
        
        cin >> ngb1 >> ngb2 >> edgeWeight ;

        adj[ngb1].push_back({ngb2 , edgeWeight}) ;
        adj[ngb2].push_back({ngb1 , edgeWeight}) ; // comment this out if the graph is directed
    }

    int src = 0 ; // assume node 0 to be the source vertex 


    // now initially for all the nodes , distance from the source node is mapped as infinity(∞)

    vector<int> distMap(n , INT_MAX) ; // index is node , distMap[index] = distance 

    // now make the dist of source node from the source node as 0 
    distMap[src] = 0;

    // initially all the nodes are "unexplored" , so we need to push all the unexplored nodes onto a min-heap , but heap does not allows random access and modification/ update of an element. So , we will use set as a min-heap , because we can do random access in set , and set is sorted , and set property works on first member of the pair.
 
    // use a set to track all the explored nodes/vertices.
    vector<bool> explored(n , false) ;

    // a node is said to be explored node if :
    // it's shortest distance from the source node has been computed and all the tensed edges incident on it have been "relaxed"

    // priority_queue<pair<int,int>> , vector<pair<int , int>> , greater<> > unexplored ; // minHeap 
    set<pair<int , int>> unexplored ; // <distance from source , node> 

    // initially all the nodes are "unexplored" , so push all the nodes onto the min-heap

    for(int i = 0 ; i < distMap.size() ; i++)
    {
        unexplored.insert({distMap[i] , i}) ; // <initial dist , node >
    }


    while( ! unexplored.empty())
    {
        auto [distCurr , currNode] = *(unexplored.begin()) ;
        // distCurr : distance of current node from the source node 

        // explore all the neighbours of current node u , if there is any tensed edge from node U to it's neighbour V , then do edge relaxation of that neighbour : V

        for(auto [ngb , edgeWeight] : adj[currNode])
        {
            // check if the neighbour ngb is explored or not 
            if(explored[ngb] == false) // not yet explored 
            {
                if(distMap[ngb] > distMap[currNode] + edgeWeight) //  distmap[currNode] is same as : distCurr
                { 
                    auto it = unexplored.find({distMap[ngb] , ngb}) ; // old tentative dist of ngb from the source , which was stored in distMap[ngb]
                    unexplored.erase(it) ;
                    
                    // we find a shorter path to reach the neighbour : ngb 
                    distMap[ngb] = distCurr + edgeWeight ;

                    // now change this dist of neighbour ngb in the unexplored set which is used instead of min-heap
                    unexplored.insert({distMap[ngb] , ngb}) ;
                }
            }
        }

        // after exiting from this above for loop , we know that , all the tensed edges from the currNode are relaxed now , and dist of curr node from the source node was already finalised , so mark this curr node as explored node , also remove this curr node from the unexplored set 

        unexplored.erase(unexplored.begin()) ;
        explored[currNode] = true ;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"distance of node : "<<i<<" from the source node "<<src<<" : "<<distMap[i]<<endl;
    }
 
    return 0 ;
}