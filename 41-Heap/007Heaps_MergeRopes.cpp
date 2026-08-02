// https://leetcode.com/problems/minimum-cost-to-connect-sticks/description/

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    vector<int> length = {4,3,2,6} ;

    // to merge n ropes into a single ropes , we will perform (n-1) merge operations 

    // greedy approach : to minimize the cost , at any point of time merge the two smallest ropes 
    // to maintain the track of the smallest ropes , we will maintain a min-heap

    int cost = 0 ; 

    priority_queue<int , vector<int> , greater<int>> ropesLength(length.begin() , length.end()) ; // initialise ropesLength heap with range constructor 

    // total time : O(n log n) : (n-1) * (3log n)
    // space : O(n) due to heap 

    while(ropesLength.size() > 1)
    {
        int rope1Length = ropesLength.top() ; // const 
        ropesLength.pop() ; // log n

        int rope2Length = ropesLength.top() ; // const
        ropesLength.pop() ; // log n

        cost += (rope1Length + rope2Length) ; // const 

        ropesLength.push(rope1Length + rope2Length); // log n 
    }
    

    cout<<"cost : "<<cost<<endl;


 
 
 
    return 0 ;
}