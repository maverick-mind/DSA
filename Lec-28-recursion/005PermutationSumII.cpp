#include<bits/stdc++.h>
using namespace std;
 
// ek time pe ek hi sol vector build kar rhe hai , that is why we are passing it by refrence , we don't want ki har function call stack ke pass khud ka ek vector ho 
void fxn( const vector<int> & candidate ,vector<int> &sol , int target  )
{
    // base case 
    if(target == 0 )
    {
        for (int i = 0; i < sol.size(); i++)
        {
            cout<<sol[i]<<" ";
        }cout<<endl;

        return ;
    }
    if(target < 0 )
    {
        return ; 
    }


    // recurrence relation
    // har location par saare elements rakhne ki possibility hai , like we can use any element for repeated number of times 
    for (int i = 0; i < candidate.size(); i++)
    {
        // select the ith element 
        // include candidate[i] into vector sol and sum both 
        target -= candidate[i] ;
        sol.push_back(candidate[i]);
        fxn(candidate , sol , target ) ; 

        // backtracking 
        target += candidate[i] ;
        sol.pop_back() ;
    }
}
 
int main() 
{
    int target = 7 ;
    vector<int> candidate = {2,3,5,7};
    vector<int> sol ; 
    fxn(candidate , sol , target );

    return 0 ;
}