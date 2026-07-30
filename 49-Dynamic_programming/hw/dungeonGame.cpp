class Solution {
public:
    // failed on 40/45th test case 
    // approach 1 : start moving from starting cell to ending cell
    // int fxnBottomUp(vector<vector<int>>& dungeon)
    // {
    //     int m = dungeon.size() ; 
    //     int n = dungeon[0].size() ;

    //     vector<vector<pair<int,int>>> dp(m , vector<pair<int,int>>(n) ) ; 
        
    //     if(dungeon[0][0] <= 0)
    //     {
    //         dp[0][0] = {dungeon[0][0] , dungeon[0][0]} ;
    //     }
    //     else{
    //         dp[0][0] = {0 , dungeon[0][0]} ;
    //     }

    //     // fill the 0th row and 0th column first as they depend only on one cell 

    //     // 0th row 
    //     for(int col = 1 ; col < n ; col++)
    //     {
    //         dp[0][col].second = dungeon[0][col] + dp[0][col-1].second ;
    //         dp[0][col].first = min(dp[0][col].second , dp[0][col-1].first) ; 
    //     }

    //     for(int row = 1 ; row < m ; row++)
    //     {
    //         dp[row][0].second = dungeon[row][0] + dp[row-1][0].second ;
    //         dp[row][0].first = min(dp[row][0].second , dp[row-1][0].first) ;
    //     }

    //     for(int row = 1 ; row < m ; row++) 
    //     {
    //         for(int col = 1 ; col < n ; col++)
    //         {
    //             dp[row][col].second = dungeon[row][col] ;

    //             if(dp[row-1][col].first > dp[row][col-1].first)
    //             {
    //                 dp[row][col].second += dp[row-1][col].second ; 

    //                 if(dp[row][col].second < dp[row-1][col].first)
    //                     dp[row][col].first = dp[row][col].second ;
    //                 else dp[row][col].first = dp[row-1][col].first ; 
    //             }
    //             else if(dp[row-1][col].first < dp[row][col-1].first){
    //                 dp[row][col].second += dp[row][col-1].second ;

    //                 if(dp[row][col].second < dp[row][col-1].first)
    //                     dp[row][col].first = dp[row][col].second ;
    //                 else dp[row][col].first = dp[row][col-1].first ; 
    //             }
    //             else if (dp[row-1][col].first == dp[row][col-1].first)
    //             {
    //                 if(dp[row-1][col].second >= dp[row][col-1].second)
    //                 {
    //                     dp[row][col].second += dp[row-1][col].second ; 

    //                     if(dp[row][col].second < dp[row-1][col].first)
    //                         dp[row][col].first = dp[row][col].second ;
    //                     else dp[row][col].first = dp[row-1][col].first ; 
    //                 }
    //                 else if(dp[row-1][col].second < dp[row][col-1].second)
    //                 {
    //                     dp[row][col].second += dp[row][col-1].second ;

    //                     if(dp[row][col].second < dp[row][col-1].first)
    //                         dp[row][col].first = dp[row][col].second ;
    //                     else dp[row][col].first = dp[row][col-1].first ; 
    //                 }
    //             }
    //         }
    //     }

    //     for(int i = 0 ; i < m ; i++)
    //     {
    //         for(int j = 0 ; j < n ; j++)
    //         {
    //             cout<<"("<<dp[i][j].first<<" , "<<dp[i][j].second<<") , " ;
    //         }cout<<endl;
    //     }

    //     if(dp[m-1][n-1].first > 0) return 1 ;
    //     else return abs(dp[m-1][n-1].first) + 1 ;

    // }

    // int calculateMinimumHP(vector<vector<int>>& dungeon) {
    //     // minimum initial health required by the knight to rescue the princes 
    //     // knight will only be alive if his health is > 0 , at health <= 0 he will die
    //     // int m = dungeon.size() ; 
    //     // int n = dungeon[0].size() ;
    //     // vector<vector<pair<int,int>>> dp(m , vector<pair<int,int>>(n , {INT_MIN , INT_MIN})) ; 
    //     // pair.first represents : lowest health drop by choosing the best path
    //     // if lowest health drop is always +ve till the knight reaches the queen cell , then he only need health 1 in this dungeon game 
    //     // pair.second represents : current health 
    //     // if doing topDown , don't initialise with -1 , because some cells can actually contain -1 , and the purpose of -1(unvisited) can conflict with the cells existing value -1 

    //     return fxnBottomUp(dungeon) ;
    // }







    // approach 2 : start moving from ending cell to starting cell 

    // healthNeed[next] = health needed before entering the next cell
    // healthNeed[curr] = max(1, healthNeed[next] - dungeon[curr]);

    // how much health the knight should have in the current cell :
    // max( 1 , health needed to reach and be alive in the next cell - health boost/loss in the current cell) , health boost/loss is dungeon[i][j]


    // Health needed before entering the current cell:

    // healthNeeded = max(
    //     1,
    //     health needed before entering the next cell - health boost/loss in the current cell
    // )
    //
    // Positive dungeon[i][j] => need less health now.
    // Negative dungeon[i][j] => need more health now.

    // To safely reach the next cell, I need whatever health the next cell demands. If the current cell heals me, I can enter with less. If it damages me, I must enter with more. But I can never enter with less than 1 HP.


    // Health required at the current cell =
    // max(1, health required at the next cell - dungeon[i][j])

    // If the current cell gives health (+), we need less before entering it.
    // If the current cell takes health (-), we need more before entering it.
    // The knight must always have at least 1 HP.

    int fxnBottomUp(vector<vector<int>>& dungeon)
    {
        // states : 
        // healthNeed[i][j] = minimum health required BEFORE entering cell (i,j)
        // so that the knight can safely reach the princess.

        int m = dungeon.size() ; 
        int n = dungeon[0].size() ; 
        vector<vector<int>> healthNeed(m , vector<int> (n)) ;

        // The knight needs at least 1 health point to survive
        healthNeed[m-1][n-1] = max(1 , 1 - dungeon[m-1][n-1]) ; // if on the last cell , value is +ve , we need only 1 health , if value is -ve we need 1 - (-ve) health

        // fill the last row and last column first 

        // fill the last row 
        for(int j = n - 2 ; j >= 0 ; j--)
        {
            // The knight needs at least 1 health point to survive
            healthNeed[m-1][j] = max(1 , healthNeed[m-1][j+1] - dungeon[m-1][j]) ; 
            // to be alive on current cell , and reach safely on next cell , healthNeeded would be maximum of 1 , difference of health needed on next cell and health on current cell 
        }

        // fill the last column 
        for(int i = m - 2 ; i >= 0 ; i--)
        {
            // The knight needs at least 1 health point to survive
            healthNeed[i][n-1] = max(1 , healthNeed[i+1][n-1] - dungeon[i][n-1]) ;
        }

        for(int i = m - 2 ; i >= 0 ; i--)
        {
            for(int j = n - 2 ; j >= 0 ; j--)
            {
                // The knight needs at least 1 health point to survive
                int op1 = max( 1 , healthNeed[i+1][j] - dungeon[i][j]) ;
                int op2 = max( 1 , healthNeed[i][j+1] - dungeon[i][j]) ;

                healthNeed[i][j] = min(op1 , op2) ;

                // we can also write 
                // healthNeed[i][j] = max ( 1 , min(healthNeed[i+1][j] , healthNeed[i][j+1]) - dungeon[i][j]) ;
            }
        }

        return healthNeed[0][0] ;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        return fxnBottomUp(dungeon) ;
    }

};