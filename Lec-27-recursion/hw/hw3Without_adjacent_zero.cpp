#include <bits/stdc++.h>
using namespace std;

void fxn(vector<string> &v, string str, int i, int n)
{
    // base case
    if (i == n)
    {
        // str.push_back('\0');
        v.push_back(str);
        return;
    }

    // recurrence relation
   if(str.empty() or str.back() != '0')
   {
    str += '0';
    fxn(v , str , i + 1 , n);
    str.pop_back();
   }


   str += '1';
   fxn(v , str , i + 1 , n);
}

vector<string> validStrings(int n)
{
    vector<string> v;
    string str = "";
    fxn(v, str, 0, n);

    return v;
}

int main()
{

    vector<string> s = validStrings(3);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }

    return 0;
}