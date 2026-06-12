#include<bits/stdc++.h>
using namespace std ; 
 
 
int main() 
{
    int m = 3 , n = 4 ;
    vector<vector<int>> v(m , vector<int>(n , 39));// m rows ke har ek column par 39 daal do 

     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
 
 
 
    return 0 ;
}