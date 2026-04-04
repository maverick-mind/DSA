#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;
    int i = 0;
    while (s[i] != '\0')
    {
        // for opening brackets , push on stack
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            stk.push(s[i]);
        }
        // for closing bracket , conditions for poping from stack
        else
        {
            // stack ke top() se compare kar ke pop karne se pahle , also check ki kahi stack empty to nahi hai
            if (!stk.empty())
            {
                if (s[i] == ')' and stk.top() == '(')stk.pop();
                else if (s[i] == '}' and stk.top() == '{')stk.pop();
                else if (s[i] == ']' and stk.top() == '[')stk.pop();
                else{ return false; }
            }
            else
            {
                return false;
            }
        }
        i++;
    }

    return stk.empty(); // agar string empty hoone tak , stack bhi empty ho gya ho then only return true karna , aisaa bhi case aa sakta hai jab , opening brackets jyaada ho closing brackets se like {}[](){{ , and string empty to ho jaaye , but stack empty na ho , uss case mein return false
}

int main()
{
    string s1 = "({[]})";
    string s2 = "()[]{}";
    string s3 = "([{]})";

    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;
    cout << isValid(s3) << endl;

    return 0;
}