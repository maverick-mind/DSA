// ek suffix ka array bna lo , jo track krega after ith index kitne b hai 
// for i = 0 to i = n-1 ka ek loop chalaao , count total number of b's jo i = 1 se n-1 tak hai , ab loop se baahar aa ke ek nayaa loop banaao , uss mein iterate start ko i = 0 se , jab bhi 'a' mile countTotalRudeness += count , i++ , fir jab bhi 'b' milee countB--;

#include<bits/stdc++.h>
using namespace std ; 
// time : n ~ O(n)
// space : O(1)
 
int rudness(const string & str)
{
    int countB = 0 ;// to track no. of b's we've seen in the suffix scanned so far
    int countRude = 0 ;
    // vector<int> suffixB(str.size() + 1 , 0);
    // int suffixB [str.size() + 1] = {0};

    for (int i = str.size() -1; i >= 0; i--)
    {
        // suffixB[i] = suffixB[i+1] +( (str[i] == 'b') ? 1 : 0);
        //  countB = countB +( (str[i] == 'b') ? 1 : 0);
        if(str[i]=='b'){
            countB++;
        }

        else if(str[i]=='a'){
            // countRude += suffixB[i+1];
            countRude += countB ;
        }
    }
    
    

    
    return countRude ;
}
 
int main() 
{
    string str = "ababbaab"; // output : 9
 
   cout<<rudness(str);
 
    return 0 ;
}