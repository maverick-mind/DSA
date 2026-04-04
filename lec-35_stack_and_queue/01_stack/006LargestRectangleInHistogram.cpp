#include<bits/stdc++.h>
using namespace std;

// area = width * height (fix the height and calculate maximum area possible for that height)
// like : har height ke liye maximum width possible nikaal lenge , and it will give har height ke liye maximum area possible , and unn sab area ka max would be larget rectangle in histogram 

// time : O(n^2)
// int largestRectangleArea(vector<int>& heights) {
    
//     int lrsf = 0 ; // largest rectangle so far
//     int n =  heights.size() ;

//     for (int i = 0; i < n; i++)
//     {
//         int rb = i ;// right boundary
//         int lb = i ;// left boundary
//         while(lb > 0 and heights[lb] >= heights[i])
//         {
//            lb-- ;
//         }
//         while( rb < n-1 and heights[rb] >= heights[i])
//         {
//            rb++ ;
//         }
//         lb++ ; 
//         rb--;

//         // current area 
//         int ca = (rb - lb + 1 ) * heights[i] ; 
//         lrsf = max(lrsf , ca);
//     }
//     return lrsf ;
// }


vector<int> nearestRightMin(vector<int> A) {

	stack<int> s; // monotonic stack // <index>
	int n = A.size();
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			// A[s.top()] cannot be the nearest smaller element to
			// the right of A[i] so we can safely pop them
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any smaller element to its right
			ans.push_back(n);
		} else {
			//  A[s.top()] is the nearest smaller element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

vector<int> nearestLeftMin(vector<int> A) {

	stack<int> s; // monotonic stack // <index>
	int n = A.size();
	vector<int> ans;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			// A[s.top()] cannot be the nearest smaller element to
			// the left of A[i] so we can safely pop them
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any smaller element to its left
			ans.push_back(-1);
		} else {
			//  A[s.top()] is the nearest smaller element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}


int largestRectangleArea(vector<int>& heights)
{
    int maxSoFar = 0 ; // to track the maximum area of rectangle in histogram 
    // for ith element as height , preCompute the index of nearest smaller value to it's left and index of nearest smaller value to it's right , and store it in vector

    // nearest smaller in left ka index 
    vector<int> nsLIdx = nearestLeftMin(heights);

    int n = heights.size() ;

    // nearest smaller in right ka index 
    vector<int> nsrIdx = nearestRightMin(heights);

 
    for (int i = 0; i < n; i++)
    {
        // find the best rectangle area with height as heights[i]

        int bestWidth = (nsrIdx[i] - nsLIdx[i] -1) ;
        int bestArea = bestWidth * heights[i] ;
        maxSoFar = max(maxSoFar , bestArea);
    }

    return maxSoFar ;

}
 
int main() 
{
    vector<int> heights = {2,1,5,6,2,3};
    
    cout<<largestRectangleArea(heights);
 
    return 0 ;
}