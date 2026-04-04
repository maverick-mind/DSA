// ek suffix ka array bna lo , jo track krega after ith index kitne b hai 
// for i = 0 to i = n-1 ka ek loop chalaao , count total number of b's jo i = 1 se n-1 tak hai , ab loop se baahar aa ke ek nayaa loop banaao , uss mein iterate start ko i = 0 se , jab bhi 'a' mile countTotalRudeness += count , i++ , fir jab bhi 'b' milee countB--;

#include<bits/stdc++.h>
using namespace std ; 
// time : n + n = 2n ~ O(n)
// space : O(n)
 
int rudness(const string & str)
{
    int countRude = 0 ;
    vector<int> suffixB(str.size() + 1 , 0);
    // int suffixB [str.size() + 1] = {0};

    for (int i = str.size() -1; i >= 0; i--)
    {
        suffixB[i] = suffixB[i+1] +( (str[i] == 'b') ? 1 : 0);
        // if(str[i] == 'b') suffixB[i] = suffixB[i+1] + 1 ;
        // else suffixB[i] = suffixB[i+1];
    }
    
    // last index par agar 'a' hua bhi to wo kisi 'b' se combine nahi ho paayega , so you can go only till str.size() - 1 or str.size() - 2
    for (int i = 0; i <= str.size() -2; i++)
    {
        if(str[i] == 'a') countRude += suffixB[i];// agar ith index par 'a' hai to suffixB[i+1] is equal to suffixB[i] hoga , so fark nahi padta ki countRude += suffixB[i] kre ya fir countRude += suffixB[i+1]
    }

    
    return countRude ;
}
 
int main() 
{
    string str = "ababbaab"; // output : 9
 
   cout<<rudness(str);
 
    return 0 ;
}