/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<bits/stdc++.h>
using namespace std;

// here min-heap is passed by value 
void printTopKInRunningStream(priority_queue<int , vector<int> , greater<> > hp)
{
    // vector<int> nums ; 

    while(hp.size() > 0)
    {
        // nums.push_back(hp.top()) ;

        cout<<hp.top()<<" ";
        hp.pop() ;
    }
    cout<<endl; 

    // for(int i = 0 ; i < nums.size() ; i++)
    // {
    //     cout<<nums[i]<<" ";
    // }cout<<endl;
}
 
 
int main() 
{
    priority_queue<int , vector<int> , greater<> > hp; // min- heap 
    int k ;
    cout<<"k : "; 
    cin >> k ;

    int input ; 


    while(cin >> input)
    {
        if(input == -1)
        {
            printTopKInRunningStream(hp) ;
        }else{
            if(hp.size() < k)
            {
                hp.push(input) ;
            }else{
                if(input > hp.top())
                {
                    hp.pop() ;
                    hp.push(input) ;
                }
            }
        }
    }

    return 0 ;
}