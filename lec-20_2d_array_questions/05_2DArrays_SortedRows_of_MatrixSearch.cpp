// each row is sorted --> go at each row and apply binary search
/*
        {40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
*/
#include<iostream>
#include<algorithm>
using namespace std ; 


bool isPresent(int mat[][3] ,int m ,int n ,int t)
{
    for (int i = 0; i < m; i++)
    {
        // search for the 't' in the ith row , use binary search in each row , as each row is sorted 
        // if(binary_search(mat[i] , mat[i] + n , t))✅
       // if(binary_search(mat[i] , mat[i+1] , t)) ❌// [mat[i] ,mat[i+1]) refer to sir one note , this may not work always , agar mat[100][100] ki hai and we used only space mat[3][4] , so rows--> 0,1,2 , columns --> 0,1,2,3 , so 2nd row ke baad garbage hai , aur 3rd row ke baad garbage hai , and if we did binary_search(mat[i] , mat[i+1] , t)) , then may be grabage value sorted order mein na ho aur binary search theek se naa lagee , so use only if(binary_search(mat[i] , mat[i] + n , t))✅ , where n is 4 
        if(binary_search(mat[i] , mat[i] + n , t))
        { // 't' is found in the ith row
            return true ;
        } 
    }
    return false ; 
}
 
int main() 
{
    int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 90;

	isPresent(mat, m, n, t) ? cout << t << " found" << endl :
	                               cout << t << " not found" << endl;

    return 0 ;
}