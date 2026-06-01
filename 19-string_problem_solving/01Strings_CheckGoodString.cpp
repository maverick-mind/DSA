#include<bits/stdc++.h>
using namespace std ; 

bool isGoodStrings(const string & str)//passing str by ref to avoid expnsive copy
{
    string vowels = "aeiou";
   for (char ch : str)
   {
       if(vowels.find(ch) == string :: npos) //OR if(vowels.find(ch) == -1)
       {
       return false ;// str will contain consonant in this case 
       }
   }

   return true ;// str is only made with vowels 

}
 
 
int main() 
{
    string str = "uoiea";

    isGoodStrings(str) ? cout<<str<<" is a good string"<<endl : cout<<str<<" is a not good string"<<endl;
    
 
    
 
    return 0 ;
}