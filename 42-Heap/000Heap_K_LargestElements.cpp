

#include<bits/stdc++.h>
using namespace std;

// approach 1 : sort the array and extract the top k values : time : O(n log n + k)


// approach 2 : on the original array , we can call max-heapify for k times , in other words transform the original array into max-heap , it will take linear time O(n)
// then extracting top k elements will take k log n time 
// total time : O(n + k log n)

void maxHeapify(vector<int> & arr , int i , int heapLength)
{
    int maxIdx = i ; 

    int leftChild = 2 * i + 1 ; 
    int rightChild = 2 * i + 2 ; 

    if(leftChild < heapLength and arr[leftChild] > arr[maxIdx])
    {
        maxIdx = leftChild ;
    }
    if(rightChild < heapLength and arr[rightChild] > arr[maxIdx])
    {
        maxIdx = rightChild ;
    }

    if(maxIdx == i) return ; 
    else{
        swap(arr[maxIdx] , arr[i]) ;
        maxHeapify(arr , maxIdx , heapLength) ;
    }
}




// approach 3 : maintain a min-heap of size k : and once k-elements are inserted , if the next elements from remaining (n-k) elements are greater than the smallest element in the min-heap , then remove the smallest element and insert this new element 

// approach 3 : size of the min heap does not depends on the size of the input array , it is always k 
void approach3_MinHeap(vector<int> & arr , int & k)
{
    priority_queue<int , vector<int> , greater<> > hp ; // space : O(k)

    for (int i = 0; i < arr.size() ; i++) 
    {   // // time : (k log k) + (n log k) - (2k log k) = (n-k) log k = (n-k) logk
        // step 1 : insert the first k elements into a min heap 
        if(hp.size() < k) 
            hp.push(arr[i]) ; // O(log k)
        
        // step 2 : iterate over remaining (n-k) elements , and for each element , check if that element is greater than minHeap.top() , if element > minHeap.top() then delete minHeap.top() and insert the current element into the minHeap 
        else if(hp.size() == k) // (n-k) 2* log k (2 because of pop and push)
        {
            if(hp.top() < arr[i])
            {
                hp.pop() ; // O(log k)
                hp.push(arr[i]) ; // O(log k)
            }
        }
    }
    
    // step 3 : extract k elements from the minHeap , and those k elements would be the k largest elements 
    while(!hp.empty()) // time : O(k log k)
    {
        cout<<hp.top()<<" ";
        hp.pop() ;
    }

    // total time : (n-k) log k + k log k ~ O(n log k)
 
}


int main() 
{
    vector<int> arr = {20 , 10 , 30 , 50 , 40 , 60} ;

    int k = 3 ; 


    // approach 2 : transform original array into a max heap and then extract top k elements 
    // time : O(n + k log n)
    // space : O(1) if heapify is done iteratively instead of recursively 
    int heapLength = arr.size() ;

    // Heap construction can start from the last non-leaf 
    // i.e. : i = heapLength / 2 - 1 , to avoid unnecessary heapify calls.
     
    for (int i = heapLength - 1; i >= 0; i--)
    {
        maxHeapify(arr , i , heapLength) ; // the original array is transformed into a max heap 
    }

    // now we want top k elements 
    while( k > 0)
    {
        cout<<arr[0]<<" ";
        swap(arr[0] , arr[--heapLength]) ; 
        maxHeapify(arr , 0 , heapLength) ;

        k-- ;
    }

    approach3_MinHeap(arr , k) ; // time : O(n log k) , space : O(k) , space is independent of input array size 
    cout<<endl;
    
    return 0 ;
}