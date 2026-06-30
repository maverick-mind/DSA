#include<bits/stdc++.h>
using namespace std;
int MOD = 1000000000 + 7 ;


// t-shirt : 100 at max 

// n (number of person) : 10 at max 

// perspective 1 : go to every person , and decide among 100 t-shirt which tshirt he will wear

// perspective 2 : go to every t-shirt and decide which person is going to wear this t-shirt 


// cannot use 100 length of bitmasking , so used a 1d vector , each index from 1 to 100 represents equivalent to each bit from 0 to 99
vector<int> id(101 , 0) ; // not gonna use 0th index , 1 to 100 index for marking if ith id t shirt is used available to pick or not , if id[i] == 0 then available to pick , if id[i] == 1 then not available to pick 

int fxnRec(int i , int n , vector<vector<int>> & friendCollection )
{
   // base case 
   if(i == n) return 1 ; 


   // recurrence relation 
   int ans = 0 ;

   for (int j = 0; j < friendCollection[i].size(); j++)
   {
       int uniqueId = friendCollection[i][j] ; 

       if(id[uniqueId] == 0) // available to use 
       {
         // use that tshirt 
         id[uniqueId] = 1 ;
         ans = (ans%MOD + fxnRec(i+1 , n , friendCollection)%MOD)%MOD ;
         id[uniqueId] = 0 ; // backtracking
       }
   }

   return ans ;
}

vector<vector<int>> dp ;

// there are many invalid states , for t-shirt id : 5 , we can have at mask 5 bits set in our bitmask , it could either be 0 setbits or 1 setbits or 2 setbits or 3 setbits or 4 setbits or 5 setbits , but it cannot be more than 5 setbits (it could never like we are on 5th t-shirt id and we have assign t-shirt to 7 men till now , at max we could assign to 5 men)
// so , because in this question , we have lot of invalid states , so it make sense to implement top don approach rather than bottom Up , because in bottom up , we would have to iterate over invalid states , and it is wasting of time 
int fxnTopDown(int tid , vector<vector<int>> & tShirtId , int & bitmask , int n)
{
    // base case 
    if(bitmask == (1 <<n) - 1) return dp[tid][bitmask] = 1 ;

    if(tid == 101) return dp[tid][bitmask] = 0 ;

    // lookups 
    if(dp[tid][bitmask] != -1) return dp[tid][bitmask] ;

    // recurrence relation
    int ans = 0 ; 

     // choice 1 : don't use this T-shirt at all
     ans = (ans%MOD + fxnTopDown(tid + 1 , tShirtId , bitmask , n)%MOD) % MOD ;

    for (int j = 0; j < tShirtId[tid].size(); j++)
    {
        int manBit = tShirtId[tid][j] ; 
        // can jth man having tid t-shirt in his collection , can he wear it ?
        // he can wear it only when , bit at manBit in the bitmask is equal to 0 

        // choice 2 : use this T-shirt for one of the eligible people
        if((bitmask & (1 << manBit)) == 0) // he can wear this tid t-shirt 
        {
            bitmask = (bitmask^(1 << manBit)) ;
            ans = (ans%MOD + fxnTopDown(tid + 1 , tShirtId , bitmask , n)%MOD) % MOD ;

            bitmask = (bitmask^(1 << manBit)) ;// backtracking 
        }
    
    }

    return dp[tid][bitmask] = ans ;
}
 
 
int main() 
{
    int t ;
    cin >> t ;
 

    while(t--)
    {
        int n ; 
        cin >> n ;
        cin.ignore() ; // to ignore the enter hit from cin >> n to be read by getline 
        vector<vector<int>> friendCollection ; // person(in row) --> tshirt collections(in column) 

        string line;
        for (int i = 0; i < n; i++)
        {
            getline(cin, line); // "5 100 1" as string 
            stringstream lineReader(line); // make the string as int : 5 100 1

            vector<int> row;
            int x;

            while (lineReader >> x) row.push_back(x); // now read each number from the line as one by one and push them in a 1d vector (row), one by one 

            friendCollection.push_back(row); // now push the entire row in the 2D vector 
        }

        // cout<<fxnRec(0 , n , friendCollection)<<endl; 

        vector<vector<int>> tShirtId(101); // tshirt with id(in row) --> people(in column) having t-shirts with that id
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < friendCollection[i].size(); j++)
            {
                int id = friendCollection[i][j] ;
                tShirtId[id].push_back(i) ; 
            }
        }

        int bitmask = 0 ; 

        // dp.resize(102 , vector<int>(1 << n, -1)) ;
        // fill(dp.begin() , dp.end() , -1) ;

        dp.assign(102, vector<int>(1 << n, -1));

        cout<<fxnTopDown(1 , tShirtId , bitmask ,n)<<endl ; // start from t-shirt id : 1


    }
 
 
    return 0 ;
}