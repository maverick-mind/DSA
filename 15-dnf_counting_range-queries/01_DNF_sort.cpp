#include <bits/stdc++.h>
using namespace std;
// in dnf sort , partitition the array into 4 parts
// region of zeroes(0 to low-1) , region of ones(low to mid-1) , region of unknown(mid to high) , region of twos (high+1 to n - 1 )
// shuruwaat mein saara array region of unknown hoga , to unknown regio mein se ek ek kar ke value pick karo aur respective region mein daalte jaao , jab unknown regio khatam ho jaaye the our array is sorted
// low pointer will point jahaa par next 0 daalenge
// mid pointer will point jahaa par next 1 daalenge
// high pointer will point jahaa par next 2 daalenge

// initially all array is unknown
// so , low = 0 , mid = 0 , high = n - 1 ; n is size of array
/* example , size 9
    input :  1 0 1 2 0 1 2 0 1
    output : 0 0 0 1 1 1 1 2 2


*/

// time : O(n)
// space : O(1)
int main()
{
    int n = 9;
    vector<int> arr(n);
    // arr = {1, 0, 1, 2, 0, 1, 2, 0, 1};
    arr = {0, 0, 0, 2, 0, 0, 2, 0, 0};

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        
        if (arr[mid] == 0)
        {// put arr[mid] in the region of zeroes
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        { // put arr[mid] in the region of ones
            mid++;
        }
        else if (arr[mid] == 2)
        {// put arr[mid] in the region of twos 
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}