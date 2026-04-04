// agar kisi sawaal mein , minimum chahiye of all the maximum 
//                         maximum chahiye of all the minimum 
// this is a strong hint ki binary search lagega 

#include<bits/stdc++.h>
using namespace std;

/*
constraints : 1 <= N <= 10  ; N is number of boards 
              1 <= K <= 10  ; K is number of painters 
              1 <= length of each board <= 10^8
              board[i] is total length of ith board
*/
 

// define bounds such that ans E [start , end]
// lower bound : scenario , number of  painters = number of boards
//                          each board is assign to 1 painter 
//                          least time taken is : maximum board lenght 
//                          (that is : max element of the array)
//                          so , time taken : max element of array (lower bound)

// upper bound , scenario , number of k painter is least , that is 1 
//                          ab 1 painter ko saara board paint karna hai 
//                          so , time taken : sum of all the unit of board , 
//                        that is : sum of all the elements of the array (upper bound)


// can 'k' painters paint 'n' boards of given length int 'mid' unit of time 
// OR rephrase it 
// How many painters are needed to paint 'n' boards in 'mid' unit of time ??
bool predicate_fxn(vector<int> board , int n , int k , int mid)
{
    // mid is the maximum time limit 
    int timeLimit = mid;
    int time = 0 ; // time used by a painter so far

    // start with 1 painter , jab time shuru hoga , tab ek painter kaam kar rha hoga , jab time exceed kar jaayega 'timeLimit' ko to 2nd painter kaa pe lagega 

    int numberOfPainter = 1 ; // start painting with a single painter 
    for (int i = 0; i < n; i++)
    {
        if(time + board[i] <= mid)
        {
            time += board[i];
        }
        else if(time + board[i] > mid)
        {
            time = 0 ;
            numberOfPainter++;
           time += board[i];
        }
    }

    return numberOfPainter <= k ; // k is the number of painters , agar numberOfPainter smaller hai 'k' se , matlab 'mid' unit of time mein , 'k' painters paint kar denge saare board 

}

int MinTimeTakenByPainters(vector<int> board , int n , int k)
{
    // lower bound : best case --> number of painters = number of board 
    // max time taken for lower bound : *max_element(board.begin() , board.end());
    int start = *max_element(board.begin() , board.end());

    // upper bound : worst case time required 
    // number of painter = 1 
    // then time taken to paint all boards : sum of all element of board
    int end = accumulate(board.begin() , board.end() , 0) ;// 0 is initial value of the sum 

    int ans = -1 ;
    
    while( start <= end) // Time : log(end - start) *time taken by predicate fxn
    {                           // log(end - start) * (size of board)
        int mid = start + (end - start)/2;

        if(predicate_fxn(board , n , k , mid)) // can 'k' painters paint 'n' boards 
        {                           // of given lengths in mid unit of time
            ans = mid ;// agar mid answer hai to kya iss se kam time mein board paints ho sakte hai ? , so for that : end = mid - 1 
            end = mid - 1 ;
        }
        else{ // agar mid time le kar saare board paint nahi ho paa rhe hai , to mid se kam value par bhi board paint nahi ho paayenge 
            start = mid + 1 ;
        }
    }
    return ans ;
}

int main() 
{
    vector<int> board = {1,3,5,2,4}; // board[i] is total length of ith board
    int n = 5 ; // number of boards (length of array --> board)
    int k = 3 ; // number of painters 
    // output : 6

    cout<<MinTimeTakenByPainters( board , n , k );

    
 
 
 
    return 0 ;
}