#include <bits/stdc++.h>
using namespace std;

vector<pair<char, bool> > nums = {
    {'0', false}, {'1', true}, {'2', true}, {'3', true}, {'4', true}, {'5', true}, {'6', true}, {'7', true}, {'8', true}, {'9', true}};

bool canPick(char last_digit, char symbol, int j)
{
    int ld = last_digit - '0';
    int cur = nums[j].first - '0';

    if (symbol == 'I')
    {
        if (cur > ld and (nums[j].second == true))
            return true;
    }

    if (symbol == 'D')
    {
        if (cur < ld and (nums[j].second == true))
            return true;
    }

    // return false if that j does not satisfies the condition with symbol I
    return false;
}

// if string pattern is of length 'n' , we need to take sequence of 'n+1'
// decisions to get the lexographically smallest string

// i --> to track the current index in string pattern
void fxn(string pattern, string ans, string &final_ans, int i)
{
    // base case
    if (ans.size() == pattern.size() + 1)
    {
        if (final_ans.empty() || ans < final_ans)
            final_ans = ans;
        return;
    }

    // recurrence relation
    // har decision ke liye we have 9 choices available
    for (int j = 1; j <= 9; j++)
    {
        // 1. agar ans string empty hai
        if (ans.empty())
        {
            ans.push_back(nums[j].first);
            nums[j].second = false;
            fxn(pattern, ans, final_ans, i);

            // backtracking
            nums[j].second = true;
            ans.pop_back();
        }

        // 2. agar ans string empty nahi hai
        else
        {

            // kya jth value ko pick kar sakte hai , ask to canPick function
            // 1. agar ha
            if (canPick(ans[ans.size() - 1], pattern[i], j))
            {
                ans.push_back(nums[j].first);
                nums[j].second = false;
                fxn(pattern, ans, final_ans, i + 1);

                // backtracking
                nums[j].second = true;
                ans.pop_back();
            }

            // 2. agar na
            else
            { // if canPick return false , simply do nothing
              // loop will do j++ and check for other value of j at that position
                continue;
            }
        }
    }
}

string smallestNumber(string pattern)
{

    string ans = "";
    string final_ans = "";
    fxn(pattern, ans, final_ans, 0);
    return final_ans;
}

int main()
{
    string pattern = "IIIDIDDD";
    string ans = smallestNumber(pattern);

    cout << ans;

    return 0;
}