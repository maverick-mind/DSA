#include <bits/stdc++.h>
using namespace std;


bool isGoodStrings(const string & str)//passing str by ref to avoid expnsive copy
{
   for (char ch : str)
   {
       if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
       {
       return false ;// str will contain consonant in this case 
       }
   }

   return true ;// str is only made with vowels 

}

// find the length of longest good substring
// time : O(n)
int longestGoodSubstring(const string & str)
{
    int maxSoFar = 0;
    // pahle substring nikaalo , fir check kro good string hai kya , agar good string hai to length nikaal lo , agar current_subString ka length badaa hai maxSoFar se , then update maxSoFar
    for (int i = 0; str[i] != '\0'; i++)
    {
        
        for (int j = i; str[j] != '\0'; j++)
        { 
            string subString = str.substr(i, (j - i + 1));

            if(isGoodStrings(subString)){
                 maxSoFar = max( maxSoFar , j - i + 1);
            }
            
        }
    }

    return maxSoFar;
}

int main()
{
    string str = "cbaeicdeiou";
    cout << longestGoodSubstring(str) << endl;

    return 0;
}