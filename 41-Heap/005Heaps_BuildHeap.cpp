// building heap from an array : 10 , 20 , 50 , 30 , 40
// transform this array is such a way that it becomes a max-heap 

// one simplest way to transform an array into a max-heap is to sort it in decreasing order 

// so , conclusion from here : 
// if an array is sorted in decreasing order : it can work like a MAX-HEAP
// if an array is sorted in increasing order : it can work like a MIN-HEAP

// but sorting will take n-logn steps , so we need to come up with a better way to transform an array into a max-heap , that will take less than O(n logn) time 

// if we visualise our array : [10 , 20 , 50 , 30 , 40] as a complete binary tree :
/*
                    10*
                  /    \ 
                20*     50 
              /   \  
             30   40

    // the nodes where max-heap property is getting violated is marked by (*) 
    // one more thing : at leaf node , no heap property (either max or min) is violated 

    // so if we fix the max-heap property on the nodes where it is getting violated , then we can say our complete binary tree is a max-heap , and to fix the max-heap property , we don't want to sort , instead on all those nodes where max-heap property is getting violated , call heapify on all those nodes , heapify will fix the heap property on the node for which we are calling heapify 

    // but we cannot call heapify in any order , to call heapify on a node , we need to make sure that the left subtree and the right subtree of that node is already following heap property 
    // and we don't need to call heapify on the leaf node , because leaf node always follow heap property , so we will call heapify only on all non-leaf nodes , and order of calling heapify is such that whenever we call a heapify for a node , it's left and right subtree should already following heap property 

    // so in the complete binary tree , we should call heapfiy from bottom(leaf node) to top(root node)


    // the number of nodes in a perfect binary tree that has n nodes at a height h is : 
    // ceil [n/(2^(h+1))] , h(height) : length of the longest path from that node to the leaf

    // for an array of size n : if we call heapify for all the non-leaf nodes (considering the tree is perfect) , total time would be : (n - number of leaf nodes)* (time taken to heapify)
    // i.e. : (n - n/2) * (time taken to heapify) ~ (n/2 * (time taken to heapify)) 

    // time taken to heapify will depend upon : height of the node on which we are calling heapify 
    // only for the root node , heapify will take O(log n) time , not for all the non-leaf nodes 
    // the time we spend on heapify : depends on the node on which we have called heapify  

    // and height of non-leaf node ranges from [1(2nd last level) to log n (root node)]

    // for a perfect tree of size : n , there will be n/2 non-leaf nodes , in worst case we are calling heapify for all non-leaf nodes
    
    total amount of work done in heapify of non-leaf nodes :

        log2n
        Σ  (n / 2^(h+1)) * O(h) : h : height of the node 
        h = 1

        total time : summation of (number of nodes at height h * time spent on every node ) for all non-leaf nodes 

        at max it would be ~ O(n) , solve it by putting upper limit of h in sigma summation as infility , and treat O(h) as h*const , it would be n*cpnst/2 * Σ h / 2^h , which would be (n*const/2) * 2 ~ (n * const) , which is ~ O(n)  

    */

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> & v , int i , const int & n) 
{
    int maxIdx = i ; 
    int leftIdx = 2 * i + 1 ;
    int rightIdx = 2 * i + 2 ;

    if(leftIdx < n and v[leftIdx] > v[maxIdx])
    {
        maxIdx = leftIdx ;
    }
    if(rightIdx < n and v[rightIdx] > v[maxIdx])
    {
        maxIdx = rightIdx ;
    }

    if(maxIdx == i) return ; 
    else {
        swap(v[i] , v[maxIdx]) ;
        heapify(v , maxIdx , n) ; 
    }
}
 
 
int main() 
{
    // vector<int> v = {1 , 3 , 2 , 7 , 5 , 4 , 6 , 9 , 8} ;
    vector<int> v = {10 , 20 , 50 , 30 , 40} ;
    int n = v.size() ;
 
    // call the heapify in the order from leaf node to root node , which means : from right to left in the vector 

    // time : O(n) : don't think , this for loop and heapify function should be more than O(n) , we have analyzed it in the above comments , how it is O(n)
    for(int i = n - 1 ; i >= 0 ; i--) // leaf to root 
    {
        // if((2*i + 1) < n and (2*i + 2) < n) // leaf nodes are handled inside the heapify function , so we can skip this if condition here  
            heapify(v , i , n) ; // call heapify at i , for the non-leaf nodes , as leaf nodes already follow heap property 
    }

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl; 
 
    return 0 ;
}