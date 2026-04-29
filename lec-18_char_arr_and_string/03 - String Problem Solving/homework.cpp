#include<bits/stdc++.h>
using namespace std;
 
bool cmp(string s1 , string s2)
{
  if(s1.size() < s2.size())
  {
    return true ; 
  }
  else if(s1.size() == s2.size())
  {
    return s1 < s2 ; 
  }

  // return ((s1.size() < s2.size()) and (s1 < s2)) ;
} 


int main() 
{
    string str = "abcde";
    vector<string> ans ; 
    for (int i = 0; str[i] != '\0'; i++) // for starting index 
    {
      int length = 1 ;
        while((i + length) <= str.size()) // for length of sub-string
        {
          string temp = str.substr(i,length) ;
            ans.push_back(temp);
            cout<<temp<<" ";
            length++;
        }
    }
    cout<<endl;

    // sort answer vector based on the length of the string inside 
    sort(ans.begin() , ans.end() , greater<string>()); // for lexographically decreasing order 

    sort(ans.begin() , ans.end() , cmp);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
 
    return 0 ;
}