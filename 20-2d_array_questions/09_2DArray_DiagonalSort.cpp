#include <bits/stdc++.h>
using namespace std;
 
void sortDiagonal(vector<vector<int> > &mat ,int m ,int n ,int i ,int j)
{
    int diaglen = min(m-i , n-j);
    for (int k = 0; k < diaglen-1; k++)
    {
        for (int L = 0; L < diaglen - k - 1  ; L++)
        {
            if(mat[i+L][j+L] > mat[i+L+1][j+L+1])
            {
                swap(mat[i+L][j+L] , mat[i+L+1][j+L+1]);
            }
        }
    }
}

vector<vector<int> > diagonalSort(vector<vector<int> > &mat)
{
    //int n = mat[0]/sizeof(mat[0][0]);
    //int m = mat/sizeof(mat[0]);
    int m = mat.size() ;
    int n = mat[0].size();

    // iterate over diagonals starting points
    // starting points could be of 2 form --> (0 , j) or (i , 0)

    // (0,j)
    for (int j = 0; j < n; j++)
    {
        sortDiagonal(mat , m , n , 0 , j);
    }

    // (i,0)
    for (int i = 1; i < m; i++)
    {
        sortDiagonal(mat , m , n , i , 0);
    }

    return mat ; 
}

int main()
{
    vector<vector<int> > mat = { {3, 3, 1, 1},
                                 {2, 2, 1, 2},
                                 {1, 1, 1, 2} };
    vector<vector<int> > ans = diagonalSort(mat);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}