#include<bits/stdc++.h>
using namespace std;
 
// Lomuto Partition
//The Lomuto partition algorithm divides an array based on a pivot element. One pointer marks the boundary for elements smaller than the pivot, while the other pointer helps in array traversal. As we traverse the array, smaller elements are moved to the left of the boundary and boundary expands. After the traversal, all elements to the left of the boundary are smaller, and those on the right are larger than pivot.

int partition( vector<int> &arr , int start , int end)
{
    int i = start - 1 ;
    int pivot = arr[end] ; 
    int j = start ;

    // for (int j = start; j < end; j++)
    while( j < end )
    {
  
        if(arr[j] <= arr[end]) //end is pivot_index , so arr[end] is pivot 
        { // or if(arr[j] <= pivot)
            // put arr[j] in left partition
            i++ ;
            swap(arr[i] , arr[j]);
           j++;
        }
        else{

                    // when arr[j] > arr[end] no need to do anything just move to the next iteration by doing j++
                    // if(arr[j] > arr[end]) // put arr[j] in right partition
            j++; 
        }
        
    
    }
    // now put the pivot element at it's correct position
    swap(arr[i+1] , arr[end]);

    return i + 1 ; // final position of pivot element 
}


void quick_sort(vector<int> & arr ,int start , int end  )
{
    // base case 
    if( start >= end) return ;

    // recurrence relation
    // 1. partition the array[start....end] around the pivot 
    int pi = partition(arr , start , end) ;  // pi : pivot index 

    // left partition 
    quick_sort(arr , start , pi-1) ;

    // right partition
    quick_sort(arr , pi + 1 , end);
   
} 

int main() 
{
    vector<int> arr = {60,50,20,10,40,30 , 15 , 21};
    int pivot = arr.size() - 1 ;
    quick_sort(arr , 0 , arr.size()-1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0 ;
}