/*
 example :
 input :
    size of array(n) : 5
    number of queries(q) : 3
    array elements : 4  1  5  2  1
            (l  r  x) it means : l se le kar r index tak x add kar do
    query1 : 0  2  5             array ke elements mein, aisaa karne se ek    query
    query2 : 2  3  2             complete ho jaayegi
    query3 : 3  4  7

    how to do it in O(q + n) time
    create an array called as difference array
    ek query operate karne ke liye : iss difference array  ke lth index par x add kar denge aur r+1 index par x minus kar denge ( aisaa karne se difference array ke l se le kar r tak ke indexes ka prefix sum x se increase kar jaayega , aur r+1th index se x minu karne se , prefix sum ka effect r ke baad waale indexes par nahi hoga) , prefix sum tab karna hai difference arrays ka jab saare query ke lth index par +x aur r+1th index par -x ho gya ho

    jab saare prefix sum aa jaaye fir unn ko original array mein add kar do , dono arrays ke ith index ko
    aisaa karna is as same as ki saare query ko ek ek kar ke lagaaya jaaye original array par

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int> arr = {4, 1, 5, 2, 3};
    // vector<int> q1 = {0, 2, 3};
    // vector<int> q2 = {2, 3, 2};
    // vector<int> q3 = {3, 4, 7};
    vector<int> diff_arr(n + 1 , 0); // ek jyaada size arr ke size se to handle r+1th index if r is last element's index

    // time : O(q+n)
    // space : O(n) due to difference array 
    int q ;
    cin>>q; // q = 3 
    //  query1 : 0  2  5    
    // query2 : 2  3  2   
    // query3 : 3  4  7
    while(q--)// this loop will run exactly q times
    {
        int l , r , x;
        cin>>l>>r>>x;
        diff_arr[l] += x;
        diff_arr[r+1] -= x ;
    }

    // now calculate prefix sum for diff_arr
    for (int i = 1; i <= n; i++)// size of diff_arr is n+1
    {
        diff_arr[i] += diff_arr[i-1];
    }
    // for (int i = 0; i < n+1; i++)
    // {
    //     cout<<diff_arr[i]<<" ";// 5 5 7 9  0
    // }
    // operation on original array arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] + diff_arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" "; // final output : 9 6 12 11 10 
    }
    
    return 0;
}