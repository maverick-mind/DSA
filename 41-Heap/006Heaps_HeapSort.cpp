// Given an array of n integers , sort them in increasing order using the heap sort algorithm 

/* 
steps for heap sort :

--> transform the array into max heap 

The root of a max heap is always the largest element.

So after every iteration:
--> The largest remaining element is placed at the end.
--> That position is never touched again.
--> The heap size shrinks by one.

--> Eventually, every element reaches its correct position.

// time : O(n log n) : build heap O(n)  +  n-1 heapify operations O(n log n)

*/

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> & v , int i , const int & n)
{
    int maxIdx = i ; 
    int leftChild = 2 * i + 1 ;
    int rightChild = 2 * i + 2 ;

    if(leftChild < n and v[leftChild] > v[maxIdx])
    {
        maxIdx = leftChild ;
    }
    if(rightChild < n and v[rightChild] > v[maxIdx])
    {
        maxIdx = rightChild ;
    }

    if(maxIdx == i) return ;
    else{
        swap(v[i] , v[maxIdx]) ;
        heapify(v , maxIdx , n) ;
    }
}
 
 
int main() 
{
    // vector<int> v = {10 , 20 , 50 , 30 , 40} ;
    vector<int> v = {1 , 3 , 2 , 7 , 5 , 4 , 6 , 9 , 8} ;
    int n = v.size() ; 


    // step 1 : transform the array into a max-heap 
    cout<<"max heap : ";
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        heapify(v , i , n) ; 
    }// now the original array is transformed into a max-heap 

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl<<endl;


    // step 2 : transform max heap into sorted array : n log n 
    int heapSize = n ; // it is the size of unsorted array starting from index : 0

    while(heapSize > 1) // n * log n 
    {
        // now the top of the heap will be the maximum element in the unsorted region and it should go to the last index of the unsorted region 
        swap(v[0] , v[heapSize-1]) ; // now , v[0] is sent to it's required index location 

        heapSize-- ; 

        // because of the swap , the heap property might be disturbed at v[0] , so fix it 
        heapify(v , 0 , heapSize) ; // we are calling heapify at index 0 for n times 
        // heapify at index 0 : log n time 
    }

    // total time : n + n log n : ~ n log n 
    // space : O(log n) due to function call stack used within heapify , we could have done heapify iterative , and it can be done constant extra space  
    
    cout<<"sorted array : " ;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
 
 
    return 0 ;
}