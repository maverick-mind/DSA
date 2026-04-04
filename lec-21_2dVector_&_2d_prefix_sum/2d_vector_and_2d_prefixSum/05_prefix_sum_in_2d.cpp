#include<bits/stdc++.h>
using namespace std ; 
 
// 1D prefix sum for ith index --> starts at 0th index and go till respective ith index 
// ind 2D prefix sum at (i,j)th index --> it starts at (0,0)th index and go till (i,j)th index 

 
int main() 
{
    vector<vector<int>> v = { {2,3,0,1,5},
                              {4,7,9,3,2},
                              {6,8,1,0,4},
                              {9,5,4,2,3},
                              {0,6,8,6,1} };
    // vector<vector<int>> prefix_sum_2d (v.size() , vactor<int>(v[0].size() , 0)) ;
    int m = v.size() ;
    int n = v[0].size();
    vector<vector<int>> prefix_sum_2d(m , vector<int>(n , 0)) ;
    
    // calculate prefix sum for each index 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==0 and j == 0){
                prefix_sum_2d[i][j] = v[i][j];
            }
            else if(i == 0 and j != 0)
            {
                 prefix_sum_2d[i][j] = prefix_sum_2d[i][j-1] + v[i][j];
            }
            else if(i != 0 and j == 0)
            {
                prefix_sum_2d[i][j] = prefix_sum_2d[i-1][j] + v[i][j];
            }
            else if(i != 0 and j != 0)
            {
                 prefix_sum_2d[i][j] = prefix_sum_2d[i-1][j] + prefix_sum_2d[i][j-1]-prefix_sum_2d[i-1][j-1] + v[i][j];
            }

               cout<<prefix_sum_2d[i][j]<<" ";
        }cout<<endl;
    }

    // now take number of queries from user , let's say q = 3;
    int q = 3;
    while(q--)
    {

        // take li, ri , lj , rj from the user 
        // (li,ri) --> top left corner position from where the sub-matrix starts 
        // (lj , rj) --> bottom right corner position at where the sub-matrix ends
        
        // sub-matrix
        // q0 --> 0,0,1,1  -->  starts at (0,0) ends at (1,1) --> ans = 16 
        // q1 --> 1,2,3,4  -->  starts at (1,2) ends at (3,4) --> ans = 28
        // q3 --> 2,0,4,1  -->  starts at (2,0) ends at (4,1) --> ans = 34
        int li , ri , lj , rj ;
        cin>>li>>ri>>lj>>rj ;
        int ans ;
        if(li > 0 and ri > 0)
        {
            ans = prefix_sum_2d[lj][rj] - prefix_sum_2d[lj][ri-1] -   
                  prefix_sum_2d[li-1][rj] + prefix_sum_2d[li-1][ri-1];
        }
        else if (li == 0 and ri != 0)
        {
            ans = prefix_sum_2d[lj][rj] - prefix_sum_2d[lj][ri-1] ;
        }
        else if ( li != 0 and ri == 0)
        {
            ans = prefix_sum_2d[lj][rj] - prefix_sum_2d[li-1][rj];
        }
        else if (li == 0 and ri == 0)
        {
            ans = prefix_sum_2d[lj][rj] ;
        }
        cout<<ans ;

    } 
 
 
    return 0 ;
}