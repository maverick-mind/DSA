// use Multi-Source BFS
// initially , insert all the sources in the queue so that whenever we access neighbour of queue.front() , we will reach the node 

/*
Instead of calling BFS multiple times for multiple number of zeroes( for every source node , we go to all the other nodes) (here we are going multiple times on a single node , each time we are going on a node because of a different zero and updating the distance of the node from the closest zero)

Rather , insert all the source node in the queue at once in the very begining , and then run normal BFS , due to this it wil gurantee , we are going on each node exactly once , and we are going on any node because of the closest zero , it will take O(m*n)
*/


class Solution {
public:
// optimised solution : multi-source BFS , consider all the 0 as source , insert all the 0 cell in the queue and do BFS for their unvisited neighbours 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // maintain a disMap matrix and initially each cell contains the value as nearest distance from 0 i.e. dist is INT_MAX , INT_MAX corresponds to unvisited , we can also initialise by -1 for unvisited ccells

        int m = mat.size() ;
        int n = mat[0].size() ;
        vector<vector<int>> distMap(m , vector<int>(n , -1)) ;

        // queue to traverse all the neighbours in such a way that the visiting order starts from considering all the 0's as the source node and exploring their neighbours in BFS order and increasing the distance by 1 each time we visit a new level of neighbours
        queue<pair<int,int>> que ; // <row , col> 

        // initially fill the queue with the indexes [i,j] as all the cells with value as 0 

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(mat[i][j] == 0)
                {
                    que.push({i,j}) ;
                    distMap[i][j] = 0 ;
                }
            }
        }

        vector<int> dr = {-1,0,0,1} ;
        vector<int> dc = {0 , -1 , 1 , 0} ;

        while(! que.empty())
        {
            auto [i,j] = que.front() ;
            que.pop() ;

            // from this [i,j] all it's neighbour in the 4 direction are at 1 + distMap[i][j]
            // visited all the unvisited neighbours of [i,j] within the grid 
            for(int k = 0 ; k < 4 ; k++)
            {
                int nr = i + dr[k] ;
                int nc = j + dc[k] ;

                // if((nr >= 0 and nr < m) and (nc >= 0 and nc < n))
                // {
                //     if(distMap[nr][nc] == -1) // unvisited cell [nr][nc]
                //     {
                //         distMap[nr][nc] = distMap[i][j] + 1 ;
                //         que.push({nr , nc}) ;
                //     }
                // }
                
                if((nr >= 0 and nr < m) and (nc >= 0 and nc < n) and (distMap[nr][nc] == -1))
                {
                    // if(distMap[nr][nc] == -1) // unvisited cell [nr][nc]
                    // {
                        distMap[nr][nc] = distMap[i][j] + 1 ;
                        que.push({nr , nc}) ;
                    // }
                }
            }
        }

        return distMap ;

    }
};