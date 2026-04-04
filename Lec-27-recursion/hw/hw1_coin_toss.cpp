#include <iostream>
using namespace std ;

void fxn(int i , int n , string str)
{
    // base case
    if(i == n)
    {
        cout<<str<<endl;
        return ;
    }
   
    // recurrence relation
   
    // 1. coin tossed and if head comes
    str += "H";
    fxn(i+1 , n , str);
   
    // 2. coin tossed and if tail comes
    str.pop_back();
    str += "T";
    fxn(i+1 , n , str);
    str.pop_back();
   
}


int main() {

int n = 3 ;
string str ="";
fxn(0,n,str);

return 0 ;
}