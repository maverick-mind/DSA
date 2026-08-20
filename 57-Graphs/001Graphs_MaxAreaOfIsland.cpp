// https://leetcode.com/problems/max-area-of-island/

// BFS Solution

class Solution {
public:

    int validNeighbours(vector<vector<int>>& grid , int m , int n ,int i , int j , queue<pair<int,int>> &q)
    {
        int currentArea = 0 ;
        q.push({i,j});

        while(!q.empty())
        {
           
            int curri = q.front().first;
            int currj = q.front().second;
            // if top contains 1 or not
            if(curri-1 >= 0 and grid[curri-1][currj] == 1)
            {
                q.push({curri-1,currj});
                grid[curri-1][currj] = -1 ; // to avoid getting count multiple times by mutual neighbour
            }
            // if bottom contains 1 or not
            if(curri + 1 < m and grid[curri+1][currj] == 1)
            {
                q.push({curri+1,currj});
                grid[curri+1][currj] = -1 ;
            }
            // if left contains 1 or not 
            if(currj - 1 >= 0 and grid[curri][currj-1] == 1)
            {
                q.push({curri , currj-1});
                grid[curri][currj-1] = -1 ;
            }
            // if right contains 1 or not
            if(currj + 1 < n and grid[curri][currj+1] == 1)
            {
                q.push({curri , currj+1});
                grid[curri][currj+1] = -1 ;
            }

            grid[curri][currj] = -1 ; // after checking all the neighbours , make it -1 , so that it's neighbour does not include it again while counting their neighbour
            q.pop();
            currentArea++; // the number of items popped from q are valid enough to make area 
        }
        return currentArea ;
    }



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> isVisited = (m , vector<int>(n , -1));
        // -2 for unvisited , 2 for visited 
        // or modify the same 2d grid , once visited , put -1 on that index [row,col]
        queue<pair<int,int>> q ; // <row , col>
        int maxArea = 0 ; 

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int currentArea  = 0 ;
                if(grid[i][j] == 1)
                {   
                    // check if neighbour of [i,j] is 1 or not 
                    currentArea = validNeighbours(grid , m , n , i , j , q) ; 
                     maxArea = max(maxArea , currentArea);
                }
            }
        } 
        return maxArea ;
    }
};


// DFS Solution
// time : O(m*n) 
// space : O(m*n) : due to function call stack in the worst case scenario , all the cells are 1 and thus there would be m*n call stack
class Solution {
public:
    int dx[4] = {0 , -1 , 1 , 0 } ; // row
    int dy[4] = {-1 , 0 , 0 , 1 } ; // column

    int dfs(vector<vector<int>>& grid , int i , int j , int m , int n)
    {
        grid[i][j] = -1 ; // visited 
        int area = 1 ; // due to grid[i][j] 

        for(int dir = 0 ; dir < 4 ; dir++)
        {
            if((i + dx[dir] < m and i + dx[dir] >= 0) and (j + dy[dir] < n and j + dy[dir] >= 0))
            {
                if(grid[i + dx[dir]] [j + dy[dir]] == 1)
                {
                    area += (dfs(grid , i + dx[dir] , j + dy[dir] , m , n)) ; // initialised with area = 1 , if no neighbour is 1 , then we will return area as 1 on the bottom of the function
                }
            }
        }

        return area ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        int maxArea = 0 ; // in worst case all the cells in the matrix can be 0

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                // if [i,j]th cell is not visited , call dfs for the island (component) connected with the [i,j]th cell

                if(grid[i][j] == 1)
                {   // visited the component of cell [i,j]
                    int area = dfs(grid , i , j , m , n) ; 

                    if(area > maxArea) maxArea = area ;
                }
            }
        }
        return maxArea ;
    }

};