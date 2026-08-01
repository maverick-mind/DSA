// pefect binary tree : all it's level are completely filled i.e. every internal node in the binary tree has exactly 2 child nodes 
// the height of a perfect binary tree is logarithmic , H : log N , (n : number of nodes)

// the number of nodes in a perfect binary tree that has n nodes at a height h is : 
// ceil [n/(2^(h+1))] , h(height) : length of the longest path from that node to the leaf 


// complete binary tree : all the level should be completely filled except for the last level which may or may not be filled. And in case the last level is partially filled then it should be filled from left to right direction 

// the height of a complete binary tree is logarithmic 
// the MAXIMUM number of nodes in a complete binary tree that has n nodes at a height h is ceil [n/(2^(h+1))] 

// as complete binary is build level-wise and each level is filled from left to right , so we can actually represent the complete binary tree using a linear data structure such as array / vector 

// for ex : to represent 7 nodes of a complete binary tree , we will make an array of size 7 , then we will assign index to each node , the order of assigning index would be same as the order in which we have inserted those nodes in the tree 
// as complete binary tree is filled level- wise , and each level is filled from left to right , so the index assigning would be in top to bottom , left-to-right direction 

// and now based on these indexing , we can assign these nodes value in an array , and thus we can represent the complete binary tree through linear data structure 

// for node at index i :
// it's left child would be at index : 2*(i+1)
// it's right child would be at index : 2*(i+2)

// for a node at index i : 
// if i is odd : it's parent would be at index : i/2 
// if i is even : it's parent would be at index : i/2 - 1

// to check if a node at index i is leaf node or not : 
// check if the index of it's left child is within the size of the array or not 
// if 2*i+1 >= n , ith node is leaf node 


// Heap does not support indexing , so we cannot do hp[idx]


// HEAP : It is a kind of complete binary tree in which every node satisfies the heap property 
// types of heap : 
        // min-heap : optimised for operations on minimim element
        // max-heap : optimised for operations on maximum element   

// min-heap : It is a kind of complete binary tree in which every node satisfies the min-heap property 
// The min-heap property states that value of each node in the heap must be less than the value of all the nodes in it's left subtree and the right subtree 

// MINIMUM value in a min-heap is present at root 


// max-heap : It is a kind of complete binary tree in which every node satisfies the max-heap property 
// The max-heap property states that value of each node in the heap must be greater than the value of all the nodes in it's left subtree and the right subtree 

// Maximum value in a max-heap is present at root 

// heap is a kind of complete binary tree and internally we can represent a complete binary tree in the form of array , so we can also represent heap internally through array 


// Heap implementation 
// push O(logn): to insert element onto the heap 
// pop O(logn): to delete and return the smallest/largest element from the heap 
// top O(1): to access the smallest/largest element without popping from the heap
// size O(1): return the size of the heap 
// empty O(1): return true if heap is empty , false otherwise 

// heap push operation : 
// the newly inserted node would be at the next position in the complete binary tree , and there is the possibility that the newly inserted node is smaller(in min heap)/greater(in max heap) than every node present in the heap to maintain the heap property , we need to do swaps as many time as the height of the complete binary tree , and as height of the complete binary tree is logarithmic , insert/ push operation would also be logarithmic : O(log (base 2) n)

#include<bits/stdc++.h>
using namespace std;

class Heap{

   
public :
    // technically , vector v and heapify should be private and cannot be access outside class , but I made it public to verify the working of the functions from outside the class 
    vector<int> v ; // internal representation of min-heap 
    // heapify -down   
    // if at any index , we are calling heapify , the heap property should be maintained in it's left and right subtree , only that ith index should be violating the heap property 
    void heapify(int i) // heapify at index : i
    {
         // swap the ith node , with smallest of [ith node , leftChild , rightChild]

            int minIdx = i ;

            int leftIdx = 2 * i + 1 ;
            if(leftIdx < v.size() and v[leftIdx] < v[minIdx])
            {
                minIdx = leftIdx ; 
            }

            int rightIdx = 2 * i + 2 ; 
            if(rightIdx < v.size() and v[rightIdx] < v[minIdx])
            {
                minIdx = rightIdx ;
            }

            if(minIdx == i) return ; 
            // else 
            swap(v[minIdx] , v[i]) ;
            heapify(minIdx) ;


    }


    // time : O(log n)
    void push(int val) // push() → heapify up
    {
        v.push_back(val) ;

        // now heapify this min-heap , by putting this val at it's correct position 
        int childIdx = v.size() - 1 ;
        int parentIdx = (childIdx % 2 != 0) ? childIdx/2 : childIdx/2 - 1;

        // while( childIdx != 0 and v[parentIdx] > v[childIdx])
        // or 
        while(parentIdx != -1 and v[parentIdx] > v[childIdx])
        {
            swap(v[parentIdx] , v[childIdx]) ;

            // childIdx = (childIdx % 2 != 0) ? childIdx/2 : childIdx/2 - 1;
            childIdx = parentIdx ;
            parentIdx = (childIdx % 2 != 0) ? childIdx/2 : childIdx/2 - 1;
        }
    }

    // time : O(log n)
    void pop() // delete the minimum value of the min-heap : pop() → heapify down
    {   // delete the root node 
        swap(v[0] , v[v.size() - 1]) ; // const
        v.pop_back() ; // const
        // heapify-down 
        heapify(0) ; // height of the tree : O(logn)
        
    }

    // time : O(1)
    int top() // return the minimum value of the min-heap , without deleting it  
    {
        if(v.empty()) return -1 ; 
        // else 
        return v[0] ;
    }

    int size(){ // return the number of elements in the min-heap 
        return v.size() ;
    }

    bool empty(){ // to check if the min-heap is empty or not 
        return v.empty() ;
    }

};
 
/*
                1
              /   \
            3       2 
          /  \    /   \ 
         7    5  4     6
       /
      8

      1 , 3 , 2 , 7 , 5 , 4 , 6 , 8
*/

 
int main() 
{
    
    Heap h ; 
    h.push(1);
    h.push(3);
    h.push(2);
    h.push(7);
    h.push(5);
    h.push(4);
    h.push(6);
    h.push(8);

    vector<int> temp = h.v ;

    for(int i = 0 ; i < temp.size() ; i++)cout<<temp[i]<<" ";
    cout<<endl;

    h.push(0);

    temp = h.v ;

    for(int i = 0 ; i < temp.size() ; i++)cout<<temp[i]<<" ";
    cout<<endl;

    h.pop() ;
    temp = h.v ;
    for(int i = 0 ; i < temp.size() ; i++)cout<<temp[i]<<" ";
    cout<<endl;

    cout<<endl;
    while(!h.empty()){ // the output is going to be sorted in increasing order 
        cout << h.top() << " " ;
        h.pop();
    }

    cout<<endl;
    cout<<h.size()<<endl;
 
    return 0 ;
}