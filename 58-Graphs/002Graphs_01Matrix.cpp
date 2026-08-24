// real world example : 
// consider every 1 as house 
// consider every 0 as hospital
// now find closest hospital from each house 

// consider all the cell with value 0 as source 


/*
Given a (m x n) binary matrix mat , for each cell find the distance to the nearest cell with the value 0 such that distance between adjacent cells(vertical or horizontal) is 1 

-- manhattan distance : Manhattan distance measures the distance between two points by moving only horizontally and vertically—like navigating city blocks.

manhattan distance , d = ∣x1 ​− x2​∣ + ∣y1 ​− y2​∣ ​
*/




// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// appr1 - brute-force
// time : (mn).(mn) ~ m^2n^2 ~ O(n^4) assuming m ~ n

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// find the manhattan dist b/w (i, j)th cell and all the other cells
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						// manhattan dist. b/w (i,j)th and (ii,jj)th cell = |ii-i| + |jj-j|
						distMat[ii][jj] = min(distMat[ii][jj],
						                      abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return distMat;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	vector<vector<int>> distMat = updateMatrix(mat);

	int m = distMat.size();
	int n = distMat[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << distMat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}