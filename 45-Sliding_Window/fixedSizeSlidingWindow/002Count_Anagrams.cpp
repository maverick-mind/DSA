#include<bits/stdc++.h>
using namespace std;
 

bool isAnagram( unordered_map<char , int> & mpt)
{
    for(auto [key , freq] : mpt)
    {
        if(freq != 0) return false ;
    }
    return true ;
}

// time : O(s.size()*t.size()) : s.size() due to iteration over s through sliding window , t.size() because of hashmap iteration in isAnagram
int anagramCount(string & s , string & t)
{
    // mpt[ch] > 0 → window is missing some occurrences of ch
    // mpt[ch] == 0 → frequency matches
    // mpt[ch] < 0 → window has extra occurrences of ch

    unordered_map<char , int> mpt ; // <char , frequency>
    // string t mein char mile , add it's fre in mpt
    // string t mein exist karta hua koi character agar window mein mile , substract it's frequency 
    // for anagrams (window , stirng t) : frequency of all key in mpt would be : 0

    int k = t.size() ;
    for(int i = 0 ; i < k ; i++)
    {
        mpt[t[i]]++;
    }

    int ans = 0 ; 

    int i = 0 , j = 0 ; 
    // iterate over the first window 
    while(j < k)
    {
        // check if the current jth char exists in string t or not 
        if(mpt.find(s[j]) != mpt.end())
        {
            mpt[s[j]]--;
        }
        j++;
    }

    if(isAnagram(mpt)) ans++;
    
    while(j < s.size())
    {
        // slide the window 
        // remove the contribution of ith char , and include the jth char 
        if(mpt.find(s[i]) != mpt.end())
        {
            mpt[s[i]]++; 
        }
        i++;
        if(mpt.find(s[j]) != mpt.end())
        {
            mpt[s[j]]--;// in a sliding window , for a character to be found in hashmap , we do freq-- ; so if same character is removed when sliding window moves ahead , do freq++ so that the ith character being removed from the window , has neutral or no affect on the freq of characters in the hashmap 
        }
        if(isAnagram(mpt)) ans++;
        j++;
    }
    
    return ans ;
}


// time : O(s.size()) : due to iteration over s 
int anagramCountTimeOptimised(string & s , string & t)
{
    // mpt[ch] > 0 → window is missing some occurrences of ch
    // mpt[ch] == 0 → frequency matches
    // mpt[ch] < 0 → window has extra occurrences of ch

    unordered_map<char , int> mpt ; // <char , frequency>
    // string t mein char mile , add it's fre in mpt
    // string t mein exist karta hua koi character agar window mein mile , substract it's frequency 
    // for anagrams (window , stirng t) : frequency of all key in mpt would be : 0

    int k = t.size() ;
    for(int i = 0 ; i < k ; i++)
    {
        mpt[t[i]]++;
    }

    int ans = 0 ; 
    int unMatched = k; // initially there are 'k' characters of string t that has not been compared to any subarray of s

    int i = 0 , j = 0 ; 
    // iterate over the first window 
    while(j < k)
    {
        // check if the current jth char exists in string t or not 
        if(mpt.find(s[j]) != mpt.end())
        {
            if(mpt[s[j]] > 0)
            {
                mpt[s[j]]-- ; // if pre-existing freq of this character is greater than 0 , then only finding it at s[j] could help could increase the possibility of getting an anagram and then only unMatched char count should be decreased 
                unMatched-- ;
            } 
        }
        j++;
    }

    if(unMatched == 0) ans++;
    
    while(j < s.size())
    {
        // slide the window 
        // remove the contribution of ith char , and include the jth char 
        if(mpt.find(s[i]) != mpt.end())
        {
            // nullify the contribution from s[i] th char in getting an aganram while moving to next window 
            // if s[i] is leaving the window, it must have been inside the window, and if it was inside the window it should have decremented mpt at some point, so mpt[s[i]] should already be <= 0 before removal
            if(mpt[s[i]] <= 0)
            {
                 mpt[s[i]]++;
                 unMatched++;
            }
           
        }
        if(mpt.find(s[j]) != mpt.end())
        {
            // this jth char from strin s[] can only contribute in making anagram if frequency of s[j] > 0 in mpt , like for ex. we have 'b' count in mpt as : 2 , and on jth char of s we have 'b' , so this b could possibly help in making anagram if we find someother 'b' in future , but if we have '0' b in hashmap , and we find 'b' at jth index of s[] , then this 'b' at jth index has NO-CONTRIBUTION in making anagram 
            if(mpt[s[j]] > 0)
            {
                mpt[s[j]]-- ;
                unMatched--;
            }
        }
       
        if(unMatched == 0) ans++;
        j++;
    }
    
    return ans ;
}

int main() 
{
    string s = "cbaebabacd"; // ans : 2
    string t = "abc";

    
    cout<<anagramCount(s,t)<<endl; 
    cout<<anagramCountTimeOptimised(s , t)<<endl;
 
    return 0 ;
}