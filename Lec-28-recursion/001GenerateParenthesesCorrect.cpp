#include<bits/stdc++.h>
using namespace std;
 
void fxn( string str , int open  , int close , int N )
{
    // base case 
    if(open == N and close == N)
    {
        cout<<str<<endl;
        return ;
    }
    // if(open > N and close > N) return ;



    // recurrence relation 
    if(open < N)
    {
        str = str + '(' ;
        fxn(str , open + 1 , close , N); 
        str.pop_back();
    }
    

    if(close < N)
    {
        str = str + ')' ;
        fxn( str , open , close + 1 , N);
        str.pop_back(); 
    }
    


} 



int main() 
{
    int N = 2; 
    int open = 0 , close = 0 ;
    string str = "";
    fxn(str , open , close , N ) ; 
 
    return 0 ;
}