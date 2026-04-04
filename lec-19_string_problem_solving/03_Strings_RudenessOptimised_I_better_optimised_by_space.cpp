// for i = 0 to i = n-1 ka ek loop chalaao , count total number of b's jo i = 1 se n-1 tak hai , ab loop se baahar aa ke ek nayaa loop banaao , uss mein iterate start ko i = 0 se , jab bhi 'a' mile countTotalRudeness += count , i++ , fir jab bhi 'b' milee countB--;

#include<bits/stdc++.h>
using namespace std ; 
 
// Time : n +n = 2n ~ O(n)
// space : O(1)
int rudness(const string & str)
{
    int countB = 0 ;
    int countRude = 0 ;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'b') countB++;
    }
    for (int i = 0; i < str.size(); i++)
    {
        // agar str[i] == 'a' ho then countRude += countB ;
        if(str[i] == 'a') countRude += countB;

        // agar str[i] == 'b' ho then countB--;
        if(str[i] == 'b') countB--;

    }

    
    return countRude ;
}
 
int main() 
{
    string str = "ababbaab"; // output : 9
 
   cout<<rudness(str);
 
    return 0 ;
}