// try to print longest good substring in 03Strings_LongestGoodSubStringOptimised

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
// ek variable banaao jo continous vowels ko track karega let's say count (count continous vowels) , aur jab bhi continously ek nayaa vowel milega , do count++; and update maxSoFar if(count > maxSoFar ) 
int longestGoodSubstring(const string & str)
{
    int maxSoFar = 0;
    int count = 0 ;
    string longestSub = "";
    string temp = "";
    for (int i = 0; i < str.size(); i++)
    {       
            // if encountered vowel at index i , 
            if(isGoodStrings(str.substr(i,1))){
                count++;
                temp.push_back(str[i]);
            } 

            else{
                 maxSoFar = max(maxSoFar , count); 
                 count = 0;
                 if(temp.size() > longestSub.size())longestSub = temp ;
                 temp.clear();

            } 
    }

    maxSoFar = max(maxSoFar , count);
    if(temp.size() > longestSub.size()) longestSub = temp;
    cout<<longestSub<<endl;
    return maxSoFar;
}

int main()
{
    string str = "cbaeicdeiou";
    cout << longestGoodSubstring(str) << endl;

    return 0;
}