/*
Bipartite Graph / 2 colouring problem : 
Given an undirected graph :
Design an algorithm to check if it is a "Bipartite" graph.

A graph is said to be a "Bipartite" graph if the graph nodes can be "partitioned" into "two independent sets" A and B such that each edge in the graph connects a node in set A and a node in set B.

partiotion nodes in 2 set such that , every edge should go from a node in set A to node in set B 
for Bipartite graph : An edge cannot connect two nodes in same set.

2-colouring problem : for a given graph , can we colour the nodes using 2 colour such that adjacent neighbouring nodes have different colour. 

*/

// If a node is assigned a colour , it means we have visited that node.


// lemma : If a graph has an odd length cycle , it cannot be biparted 
// It the graph is a tree , It is always biparted (alternate colours between levels)



// 785. Is Graph Bipartite?

// 2 colouring problem
class Solution {
    bool dfs(vector<vector<int>>& graph , vector<int> & visited , int currentNode , int parentNode)
    {                    
        if(parentNode != -1 and visited[parentNode] == 1)
        {
            // mark the currentNode as visited , and assign it a colour
            visited[currentNode] = 2 ; // which is different from it's parent's colour
        }  
        else{
            visited[currentNode] = 1 ;
        }
        

        for(auto & neighbour : graph[currentNode])
        {
            // if neighbour is already coloured with the colour same as currentNode colour , return false
            if(visited[neighbour] == visited[currentNode])
            {
                return false ;
            }else if(visited[neighbour] == 0) // neighbour is not visited  
            {
                if(dfs(graph , visited , neighbour , currentNode) == false)
                {
                    return false ;
                }
            }
        }

        return true ; // if no adjacent neighbour clash with having the same colour or we can say that component of current is bipartite.

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // write the code considering multiple components of graph

        int n = graph.size() ;

        vector<int> visited(n , 0) ; // visited[i] = 0 means unvisited 
                                     // visited[i] = 1 means visited and colour 1 is assigned 
                                     // visited[i] = 2 means visited and colour 2 is assigned 
        // can we colour the nodes using 2 colour such that adjacent neighbouring nodes have different colour.

        bool isBipartite = true ;

        for(int i = 0 ; i < n ; i++)
        {
            if(visited[i] == 0)// 0 for unvisited 
            {
                if(dfs(graph , visited , i , -1) == false)
                {
                    isBipartite = false ;
                    break ;
                }
            }
        }

        return isBipartite ;
    }
};

// bfs solution 

bool bfs(vector<vector<int>>& graph , vector<int> & visited , int startingNode)
{
    queue<int> que ;

    // consider a node as starting node , mark it visited by assigning it a colour and insert it into the queue

    que.push(startingNode) ;
    visited[startingNode] = 0 ;

    
    while(! que.empty())
    {
        int currentNode = que.front() ;
        que.pop() ; 

        // iterate over all the neighbours of the currentNode , if they are already coloured , compare the colour , if they are not visited , assign them an alternate colour ohter than parent colour
        for(auto & neighbour : graph[currentNode])
        {
            if(visited[neighbour] == -1) // neighbour is still not visited 
            {   // assign the neighbour alternate colour , other than the parent colour
                visited[neighbour] = 1 - visited[currentNode] ;
                // OR
                // visited[neighbour] = 1 ^ visited[currentNode]
                que.push(neighbour) ;
            }
            else{ // if the neighbour is visited 
                if(visited[neighbour] == visited[currentNode])
                {   // component of currentNode is not Bipartite
                    return false ;
                }
            }
        }
    } 

    // component of currentNde is Bipartite 
    return true ;

}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size() ;
    vector<int> visited(n , -1) ; // -1 means unvisited 
                                    // 0 means visited and coloured with red 
                                    // 1 means visited and coloured with green

    bool isGraphBipartite = true ;

    // check bipartite for all the component of the graph
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == -1)
        {
            if(bfs(graph , visited , i) == false)
            {
                isGraphBipartite = false ;
                break ;
            }
        }
    }
    return isGraphBipartite ;
}