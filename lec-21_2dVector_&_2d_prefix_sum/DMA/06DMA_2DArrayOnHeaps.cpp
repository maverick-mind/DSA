// create a 2d array in heap of size m x n
// it means , create an array of size 'm' on the heap , whose each element is an array of integers of size 'n' 

#include<iostream>
using namespace std ; 
 
 
int main() 
{
    int n , m ; 
    cin>>m>>n;

    // ptr is a pointer to an integer pointer 
     int* *ptr = new int *[m] ; // heap par jaao 'new' se , aur ek array banaao 'm' size ka jiss ka har ek element ek integer pointer ho (int*)

     for (int i = 0; i < m; i++)
     {
         ptr[i] = new int[n] ; //in the heap , ptr[i] pointer point kar rha hai ek 1d array of integers ko jiss ka size n hai 
     }
    

     // read the values in the 2d array 
     for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cin>>ptr[i][j];
         }
     }

     // print the values in the 2d array 
     for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout<<ptr[i][j]<<" ";
         }cout<<endl;
     }

     // deallocate memory for 2d array
     for (int i = 0; i < m; i++)
     {
         delete [] ptr[i];// ptr[i] points to an integer array 
     }
     delete [] ptr ; 
 
 
 
    return 0 ;
}