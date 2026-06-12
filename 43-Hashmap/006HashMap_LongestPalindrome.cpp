#include<bits/stdc++.h>
using namespace std;
 
// for a palindrome you can use:
// All even frequencies completely.
// For every odd frequency f, you can use f - 1 characters.
// And if at least one odd frequency exists, you can put one odd character in the center.

// time : nlogn , when we are using set<>
// time : on avg. O(n) when we are using unordered_set<> , but worst case O(n^2)
// space : O(n) in worst case , due to set<>/unordered_set<>

// use set : pahli baar koi element mile , insert it in set , next time fir se wahi element mile then erase that element from set and make ans += 2 , and at the end set mein sirf sinlge characters bach jaayenge , after all these agar set ka size() > 0 hai then ans++
int LongestPalindromeUsingSet(const string & str)
{
    set<char> st ;
    int ans = 0 ;

    for(auto it : str)
    {
        if(st.find(it) != st.end()) // for ex. pahle se 'c' thaa , ab fir se 'c' mill gya , now ans += 2 
        {// because 'c' count is 2 , now delete 'c' from the set , to do the same again for future counts of 'c'
            st.erase(it);
            ans += 2 ;
        }else {
            st.insert(it);
        }
    }

    if(st.size() == 0) return ans ;

    return ans + 1 ;
}

int main() 
{
    string str = "abccccdd";// by-rearranging the string , what is the maximum length of palindrome that can be created 
    cout<<LongestPalindromeUsingSet(str)<<endl;

 
 
 
    return 0 ;
}