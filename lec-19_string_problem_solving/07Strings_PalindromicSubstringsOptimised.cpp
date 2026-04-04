// break solution into 2 parts
// part 1 --> find out number of odd length pallindromic substring
//            a pallindromic string of odd length has 1-char at it's centre 
// left to right iterate karte hue hum ye check karenge ki with this character at the centre kitni pallindromic substrings bann sakti hai 


// part 2 --> find out number of even length pallindromic substring 
//            a pallindromic string of even length has 2-identical char at it's centre   
// left to right iterate karte hue hum ye check karenge ki with these 2 identical characters at the centre kitni pallindromic substrings bann sakti hai        


// time : n^2 + n^2 = 2n^2 ~ O(n^2)
// space : O(1)
#include<bits/stdc++.h>
using namespace std ; 

int countPallindromicSubstring(const string & s)
{
    int finalCount = 0 , countOdd = 0 , countEven = 0;
    // part 1 : check for odd length of pallindromic substring (also, har ek character khud mein ek pallindromic substring hai) , we can build with str[i] as centre 
    // iterate kro left to right , aur har element ko centre maan ke uss ke left-- aur right++ ko compare karna start kro 
    for (int i = 0; i < s.size(); i++)
    {
        // countOdd++; 
        int left = i , right = i ;// har ek character khud mein ek pallindromic substring hai ,  that is why both left and right is at i
        while(left >= 0 and right < s.size()){
            if(s[left] == s[right])
            {
                countOdd++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
    }

    // part 2 : check for even length of pallindromic substring (also, centre ke 2 chars same honge even pallindromic substring mein) ,  we can build with str[i] and str[i+1] as centre 
    // iterate kro left to right , aur har 2 continous characters ko centre maan ke uss ke left-- aur right++ ko compare karna start kro
    for (int i = 0; i < s.size(); i++)
    {
        int left = i , right = i+1 ;
        while(left >= 0 and right < s.size())
        {
            if(s[left] == s[right])
            {
                countEven++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
    }

    finalCount = countOdd + countEven ;
    return finalCount ;
}
 
int main() 
{
    string s = "abaaba";
 
    cout<<countPallindromicSubstring(s);
 
    return 0 ;
}