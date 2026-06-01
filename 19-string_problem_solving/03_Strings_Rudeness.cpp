#include<bits/stdc++.h>
using namespace std ; 
 
int rudness(const string & str)
{
    int count = 0 ;
    for (int i = 0; i <= str.size()-2; i++)
    {
        for (int j = i+1; j <= str.size()-1; j++)
        {
            if(str[i] == 'b') continue ;
            else if(str[i] == 'a'){
                if(str[j] == 'b') count++;
            }
        }
    }
    return count ;
}
 
int main() 
{
    string str = "ababbaab"; // output : 9
 
   cout<<rudness(str);
 
    return 0 ;
}