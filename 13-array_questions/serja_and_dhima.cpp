#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n = 7 ; // no. of cards on the table
    vector<int> v = {1,2,3,4,5,6,7} ;

    int left = 0 , right = n -1 ;
    int ss = 0 ; // serja's score
    int ds = 0 ; // dhimma score

    while(left <= right)
    {
        // serja's turn first to pick a card , either from left end or right end , which one is larget 
        if(v[left] > v[right])
        {
            ss += v[left];
            left++;
        }
        else{
            ss+= v[right];
            right--;
        }
        

        // dhimma's turn
        if(left <= right)
        {
             if(v[left] > v[right])
        {
            ds += v[left];
            left++;
        }
        else{
            ds+= v[right];
            right--;
        }

        } 
        
    }

    cout<<max(ss,ds);

 
    return 0 ;
}