#include<iostream>
#include<string>

using namespace std;

// a string of size n has n(n+1)/2 ~ n^2 substrings

void generateSubstrings(const string& strRef) { // we are passing by const refrence to avoid the copy, and refrence is made const to make our intention clear that we are not passing string by & so that we want that changes made inside function will reflect in original string str , instead we don't want to make changes in original string str that is why const , but we are passing string by & because we don't want to make copy of original string str , coz making copy is expensive 
	int n = strRef.size();
	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// generate the substring that starts at the
			// ith index and ends at the jth index
			string subString = strRef.substr(i, j - i + 1);
			cout << subString << endl;
		}
		cout << endl;
	}
}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str);

	return 0;
}