// https://leetcode.com/problem-list/counting-sort/
// counting sort questions on leetcode 
#include <bits/stdc++.h>
using namespace std;
// counting sort : unstable sort algorithm 
/*
example :
    input : n = 9
    array[n] = {1,0,3,2,3,1,2,0,2};
    k = 3

    output : 0 0 0 1 1 2 2 2 3 3
*/

int main()
{
    int n = 9;
    int array[9] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
    int k = 3;

    int frequency_array[k + 1] = {0};

    // fill the frequency_array
    for (int i = 0; i < n; i++)
    {
        frequency_array[array[i]]++;
    }

    // sort the original array
    // int count = 0;
    // for (int i = 0; i <= k; i++)
    // {
    //     if (frequency_array[i] > 0)
    //     {
    //         for (int j = 1; j <= frequency_array[i]; j++)
    //         {
    //             array[count++] = i;
    //         }
    //     }
    // }
    //OR , another way


    // time : O(n)
    int number = 0; int index = 0 ;
    while(number <= k)
    {
        while(frequency_array[number] >= 1)
        {
            array[index] = number ;
            index++;
            frequency_array[number]--;
        }
        number++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}