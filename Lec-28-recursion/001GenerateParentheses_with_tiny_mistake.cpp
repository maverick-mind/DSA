/* 
Generate N pairs of parenthesis , design a recursive solution to generate all the combinations of parenthesis.

Ex. 
    Input : N = 2 
    outut : "(())" , "()()" , ")()(" , ....

*/

#include<bits/stdc++.h>
using namespace std;

void fxn( string str , int n , int open , int close )
{

    // base case 
    if(open > n and close > n) return ;
    if(open == n and close == n)
    {
        cout<<str<<endl;
        return ;
    }

    // recurrence relation
    // 1. insert '(' if open < n  
    if(open < n){
         fxn(str +'(' , n , open + 1 , close) ;  // the tiny issue doing this way is , ki hum str + '(' kar ke arguement mein bhej rhe hai , but backtracking karte time pop_back() kar de rhe hai , it means ki hamne update kar ke arguement mein jo bheja wo next call mein show up hoga , but hamne ek call pahle ke liye pop_back() kar diya , to avoid it , use  str = str + '(' ; and pas just str in arguement 
         str.pop_back();  // backtracking , remove '('
    }
    //  str.pop_back(); 

    // 2. insert ')' if close < n
    if(close < n)
    {
        fxn(str +')' , n , open , close + 1 ) ;
        str.pop_back(); // backtracking , remove ')'
    }  
    //  str.pop_back();

}
 
int main() 
{
    int n = 2 ;
    int open = 0 ;
    int close = 0 ; 
    string str = "";
    fxn( str , n , open , close );
 
    return 0 ;
}

/* 
((()
(())
(())
(())
(()(
()()
()))
()))
())(
()()
()))
())(
()()
())(
()((
)(()
)())
)())
)()(
))()
))))
)))(
))()
)))(
))((
)(()
)())
)()(
))()
)))(
))((
)(()
)()(
))((
)(((
*/