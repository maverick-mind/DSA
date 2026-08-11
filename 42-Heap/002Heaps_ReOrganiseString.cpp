#include<bits/stdc++.h>
using namespace std;
 
string reorganizeString(string s)
{
    // unordered_map<char , int> mp ; 

    // for (int i = 0; i < s.size(); i++)
    // {
    //     mp[s[i]]++;
    // }

    // the string only conatain lowercase english character , so use vector<freq> instead of unordered map 
    vector<int> freq(26 , 0) ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        freq[s[i] - 'a']++ ;
    }

    priority_queue< pair<int , char>> hp ; // by default , heap is created by comparing first member of the pair 

    for(int i = 0 ; i < 26 ; i++)
    {
        if(freq[i] != 0)
            hp.push({freq[i] , 'a' + i}) ;
    }

    string ans  ;
    ans.reserve(s.size()); // it increases the capacity to s.size() , not the size , so we don't need to increase the capacity after every push_back() ; and it can save some time 

    while(hp.size() > 0)
    {
        auto [freq1 , ch1] = hp.top() ; 
        hp.pop() ; 
        freq1-- ;
        if(!ans.empty() and ans.back() == ch1) return "" ; // once two adjacent characters are same , we get our answer as ""
        ans.push_back(ch1) ;

        int freq2 = 0 ; char ch2 = '@' ; // initialize freq2 with 0 and ch2 with non- lowercase 

        if(hp.size() > 0)
        {
            // tie (freq2 , ch2) = hp.top() ; // tie creates a tuple of references to those variables and assigns into them.
            // There is a small amount of extra work compared to direct initialization, but it's tiny.

            // Use auto [a, b] = ...; when declaring new variables.
            // Use tie(a, b) = ...; only when you already have variables and want to assign
            
            pair<int , char> p = hp.top() ; 
            freq2 = p.first ;
            ch2 = p.second ;
            hp.pop() ;
            ans.push_back(ch2) ;
            freq2-- ; 
        }

        // insertion in the heap would be done only after both the elements are extracted and used 
        if(freq1 != 0) hp.push({freq1 , ch1}) ;

        if(freq2 != 0) hp.push({freq2 , ch2}) ;
        // cout<<"hi ";
    }

    return ans ;
}
int main() 
{
    string s = "aaaaabbbbcccdd" ;

    cout<<reorganizeString(s) ;
 
 
    return 0 ;
}