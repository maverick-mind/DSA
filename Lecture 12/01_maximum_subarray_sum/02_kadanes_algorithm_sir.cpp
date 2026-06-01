#include<iostream>
using namespace std ; 

int kadanes( int array[] , int n)
{
    int max_subarray_sum_so_far[n];// ith index par 
    max_subarray_sum_so_far[0] = array[0];
    int max_sum_so_far = array[0];

    for (int i = 1; i < n; i++)
    {
       max_subarray_sum_so_far[i] = max(array[i] , max_subarray_sum_so_far[i-1] + array[i]);
       max_sum_so_far = max(max_subarray_sum_so_far[i] , max_sum_so_far);

    }
     return max_sum_so_far;
}

int kadanes_space_optimized( int array[] , int n)
{
    int max_subarray_sum_so_far = array[0];
    int max_sum_so_far = array[0];
    for(int i = 1 ; i < n ; i++)
    {
    //   max_subarray_sum_so_far = max(max_subarray_sum_so_far + array[i] , array[i]);
    //   max_sum_so_far = max( max_sum_so_far , max_subarray_sum_so_far );

      max_sum_so_far = max( max_sum_so_far , max_subarray_sum_so_far = max(max_subarray_sum_so_far + array[i] , array[i])); // wowwwwwww , syntax worked 

    }

    return max_sum_so_far;

}
 
 
int main() 
{
    int array[] = {-3 , 2 , -1 , 4 , -5};
    int n = sizeof(array)/sizeof(array[0]);

    cout<<kadanes(array , n)<<endl;
    cout<<kadanes_space_optimized(array , n)<<endl;
    return 0 ;
}