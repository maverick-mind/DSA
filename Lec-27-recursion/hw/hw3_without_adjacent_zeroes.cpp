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
    // 0 daalne pe constraint hai , 1 pe nahi , so 0 daalne ke time check
    // karo ki (i-1)th position par 0 hai ya nahi , agar hai to 0 , agar
    // nahi hai to 1 , but 1 daalne ke liye koi constraint nahi hai

    // 1st. put 0
    str += "0";
    if (i >= 1)
    {
        if (str[i - 1] == '0')
        {
            str[i] = '1';
        }
        // if(str[str.length() - 1] == '0') {
        //     str[str.length() - 1] = '1';
        // }
    }

    fxn(v, str, i + 1, n);
    str.pop_back();

    // 2nd. put 1
    str += "1";
    fxn(v, str, i + 1, n);
    str.pop_back();
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