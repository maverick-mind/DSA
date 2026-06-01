#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, vector<string> > phoneMap;

    phoneMap["Rohan"].push_back("1234");
	phoneMap["Rohan"].push_back("5678");
	phoneMap["Shashwat"].push_back("0000");
	phoneMap["Shashwat"].push_back("1111");
	phoneMap["Aarish"].push_back("12345");

    for(pair<string,vector<string>> contact : phoneMap)
    {
        string name = contact.first ;
        vector<string> nums = contact.second;
        cout<<name<<" : ";
        for(auto it : nums)
        {
            cout<<it<<"  ";
        }cout<<endl;
    }

    cout<<endl ;
    // structural binding syntax
    for(auto [name , nums] : phoneMap)
    {
        cout<<name<<" : ";
        for(auto it : nums)
        {
            cout<<it<<"  ";
        }cout<<endl;
    }

    return 0;
}