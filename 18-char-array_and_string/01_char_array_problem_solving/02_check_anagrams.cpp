// anagrams --> a word or phrase that is made by arranging the letters of another word or phrase in a different order
// Given a two strings represented as a character arrays , check if they are anagrams 
// note : assume characters of the input strings are lowecase letters 
// example :  Input               Output 
//      "state" and "taste"       true
//           "abacbac"            false 

#include<iostream>
#include<cstring>
using namespace std ; 
// solution 1
// maintain a frequency array for str1 , aur str2 ke character par iterate karte jaao aur frequency array mein value ko 1 se minus kar dena agar koi element encounter ho , aur last mein frequency array par iterate kar lo , agar saare elements ki value 0 hui to dono strings anagram hai , if anyone element is not 0 then these 2 strings are not anagrams 

// steps : n + 26 ~ O(n)
// size : O(26)  <-- for the 26 characters 
bool checkAnagrams ( char str1[] , char str2[])
{
    int freq[26] = {0};
    // check if both the strings are of same size or not
    if(strlen(str1) != strlen(str2)) return false ;
    else{
        for (int i = 0; i < strlen(str1); i++)
        {// str1[i] != '\0' ye stopping condition bhi daal sakte thee 
            // str1 ke regarding freq array mein value++ kar do
            freq[str1[i] - 'a']++;

            // str2 ke regarding freq array mein value-- kar do
            freq[str2[i] - 'a']--;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if(freq[i] != 0) return false ;
    }

    return true ;


}



// solution 2 
// if length of str1 != length of str2 --> then both are not anagrams 
// if lenght is same , then sort both the strings and compare each element , if all element matched then they are anagrams , else they are not anagrams 
 
 
int main() 
{
    char str1[] = "hello";
    char str2[] = "ohell";

    checkAnagrams(str1 , str2) ? cout<<"Anagrams"<<endl : cout<<"Not Anagrams"<<endl;
 
 
 
    return 0 ;
}