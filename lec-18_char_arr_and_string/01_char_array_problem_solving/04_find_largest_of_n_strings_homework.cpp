#include <bits/stdc++.h>
using namespace std;

int cmp_two_str(string s1 , string s2)
{
  int i = 0  ;
  while(s1[i] != '\0' and s2[i] != '\0')
  {
    if(s1[i] > s2[i]) return 1 ; 
    else if(s1[i] < s2[i]) return -1 ;
    else i++ ;
  }

  if( i < s1.size()) // s1 is bigger 
  {
    return 1;
  }
  else if(i < s2.size()) { // s2 is bigger
    return -1;
  }
  else return 0 ; 

}

string lexo_largest_among_n(vector<string> str)
{
  int idx1 = 0 ; 
  int idx2 = 1;
  while(idx1 < str.size() and idx2 < str.size())
  {

    // now compare idx2 with idx1 value 
    int temp = cmp_two_str(str[idx1] , str[idx2]) ; 
    if(temp == 1) // str[idx1] is greater 
    {
       idx2++ ;  // idx2 is smaller , idx2 should be moved to next index to be compared with 
    }
    else if(temp == -1) // str[idx2] is greater 
    {
      idx1 = idx2 + 1 ; // idx1 is smaller , idx1 should be moved to next index to be compared with 
    }
    // else --> both are equal , kisi ek ko aage badhaa do , we still have one of the same string to compare the next string ahead 
    else idx2++ ; 
  }
  return str[min(idx1 , idx2)] ; 

}


string lexo_largest(vector<string> &str)
{
    string largest = str[0];

    for(int i = 1; i < str.size(); i++)
    {
        if(str[i] > largest)
            largest = str[i];
    }

    return largest;
}

int main()
{
  vector<string > str = {"abc", "ae",  "xyz", "zz", "zzc", "zza" , "zzz"};

  string ans = *max_element(str.begin(), str.end()); // one line solution 
  cout << lexo_largest_among_n(str)<<endl;
  cout<<ans<<endl ;
  cout<< lexo_largest(str) ; 

  return 0;
}