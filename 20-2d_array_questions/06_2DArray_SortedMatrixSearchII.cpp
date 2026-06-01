// homework in sir one note on leetcode 
#include<bits/stdc++.h>
using namespace std ; 
 
bool isPresent(int mat[][3] , int m , int n , int t)
{
    int i = 0 ;
     int j = n - 1 ;
     while(i < m and j >= 0)
     {
        if(t == mat[i][j])
        {
            return true ;
        }
        else if( t >  mat[i][j])
        {
            i++;
        }
        else if( t < mat[i][j])
        {
            j--;
        }
     }


     return false ;

}
 
int main() 
{
    int mat[][3] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 80;

	isPresent(mat, m, n, t) ? cout << t << " found" << endl :
	                               cout << t << " not found" << endl;
 
 
 
    return 0 ;
}