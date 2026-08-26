
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q ; // <row,col>
        int m = grid.size() ;
        int n = grid[0].size();
        int cogoitb = 0 ; // count of good oranges in the begining 
        int coec = 0 ; // count of empty cells 
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(grid[i][j] == 1) cogoitb++;
                if(grid[i][j] == 0 )coec++;
            }
        }

        // if all the cells are empty , then minimum time taken so that no fresh oranges are there would be : 0 seconds 
        if(coec == (m)*(n)) return 0 ; 
        

        int minutesPassed = -1 ;

        while(!q.empty())
        {
            int currentQueueSize = q.size() ;

            while(currentQueueSize--)
            {
                auto [row , col] = q.front();  
                // check any fresh oranges around the current rotten orange
                // left
                if(col - 1 >= 0)
                {
                    if(grid[row][col-1] == 1)
                    {
                        grid[row][col-1] = 2 ;
                        q.push({row,col-1});
                        cogoitb--;
                    }
                }
                // right
                if(col + 1 < n)
                {
                    if(grid[row][col+1] == 1)
                    {
                        grid[row][col+1] = 2 ;
                        q.push({row,col+1});
                        cogoitb--;
                    }
                }
                // up
                if(row - 1 >= 0)
                {
                    if(grid[row-1][col] == 1)
                    {
                        grid[row-1][col] = 2 ;
                        q.push({row-1,col});
                        cogoitb--;
                    }
                }
                // down 
                if(row + 1 < m)
                {
                    if(grid[row+1][col] == 1)
                    {
                        grid[row+1][col] = 2 ;
                        q.push({row+1,col});
                        cogoitb--;
                    }
                }
                q.pop();
            }
                minutesPassed++;
        }
        
        if(cogoitb == 0)
        {
            return minutesPassed;
        }else{
            return -1;
        }
    }
};


// similar to 542 : 01-matrix
// apply shortest single source path distance , but consider multi-source bfs as initially there can be multiple rotten oranges 
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        // 0 --> empty cell 
        // 1 --> fresh orange
        // 2 --> rotten orange

        int dx[] = {1 , -1 , 0 , 0} ;
        int dy[] = {0 , 0 , 1 , -1} ;

        // multi-source bfs 
        // we will modify the original grid :
        // a fresh orange cell if it has a rotten orange in it's neighbour it will be modified to minimum distance of this fresh orange from any nearest rotten oranges which were rotten initially
        // empty cell , after visiting --> modified into -1

        int freshCount = 0 ; 
        int minTime = 0 ; // minimum time taken by all the oranges to be rotten would be the minimum time taken by the last(farthest) orange to be rotten

        queue<pair<int , int>> que ; // <row , col>
        // initially insert all the rotten oranges cell in the queue
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 2)
                {
                    grid[i][j] = 0 ; // distance of rotten orange from nearest rotten orange , or time taken to rot a rotten orange is : 0 
                    que.push({i,j}) ;
                }
                else if(grid[i][j] == 0)
                {
                    grid[i][j] = -1 ; // an empty cell cannot be rotten 
                }
                else if(grid[i][j] == 1)
                {
                    grid[i][j] = -2 ;
                    freshCount++ ;
                }
            }
        }

        // for(int i = 0 ; i < m ; i++)
        // {
        //     for(int j = 0 ; j < n ; j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;


        // now the grid looks like : 
        // rotten oranges : 0 
        // empty cell : -1
        // fresh oranges : -2

        while((! que.empty()) and freshCount > 0) // once freshCount == 0
        {                                   // there is no need to check further 
                                            // in the grid
            auto [i,j] = que.front() ;
            que.pop() ;

            // travel to the neighbour of [i,j]
            for(int k = 0 ; k < 4 ; k++)
            {
                int nr = i + dx[k] ;
                int nc = j + dy[k] ;

                if((nr >= 0 and nr < m) and (nc >= 0 and nc < n) and grid[nr][nc] == -2)
                {
                    // fresh orange ready to be rotten 
                    freshCount-- ;
                    // the neighbour of a rotten orange will take 1 minute more than the neighbour to be rotten
                    grid[nr][nc] = 1 + grid[i][j] ;
                    que.push({nr,nc}) ;

                    if(grid[nr][nc] > minTime)
                    {
                        minTime = grid[nr][nc] ; // min time to rot all the oranges would be the time takne by the last orange is rotten
                    }
                }
            }
        } 

        // cout<<"freshCount : "<<freshCount<<endl;
        // cout<<minTime<<endl<<endl;
        

        // for(int i = 0 ; i < m ; i++)
        // {
        //     for(int j = 0 ; j < n ; j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;

        return (freshCount == 0) ? minTime : -1 ; // if all initial fresh oranges are rotten now then only return the time taken for all to rot 

    }
};