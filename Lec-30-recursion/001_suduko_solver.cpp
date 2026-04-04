#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<char> > &board, int i, int j, int val)
{
    // check in the current row , if the value already exist
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == char('0' + val))
        {
            return false;
        }
    }

    // check in the current col , if the value already exist
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == char('0' + val))
        {
            return false;
        }
    }

    // check if it does not exist in 3 x 3 sub-matrix
    int row_start = (i / 3) * 3;
    int col_start = (j / 3) * 3;
    for (int r_itr = row_start; r_itr < row_start + 3; r_itr++)
    {
        for (int c_itr = col_start; c_itr < col_start + 3; c_itr++)
        {
            if (board[r_itr][c_itr] == char('0' + val))
                return false;
        }
    }
    return true;
}

bool fxn(vector<vector<char> > &board, int i, int j)
{
    // cout << "HI" << endl;
    // base case
    if (i == board.size())
    {
        // for (int k = 0; k < board.size(); k++)
        // {
        //     for (int g = 0; g < board[k].size(); g++)
        //     {
        //         cout << board[k][g];
        //     }
        //     cout << endl;
        // }
        return true;
    }
    // if(j >= board.size() and i >= board.size()) return ;
    if (j >= board.size())
    {
        return  fxn(board , i + 1 , 0) ; 
    }

    // recurrence relation

    if (board[i][j] == '.')
    {
        for (int val = 1; val <= 9; val++)
        {
            if (canPlace(board, i, j, val))
            {

                board[i][j] = char('0' + val);
                if(fxn(board, i, j + 1)) return true ; // stop recursion
                board[i][j] = '.'; // backtracking
            }
        }
      return false; // no valid number can be assigned at that ( i , j ) , so we return false 
    }
    //else if (board[i][j] != '.')
    else // board[i][j] != '.' ; it means there is already a correct number at (i,j)th location , so check for (i , j+1)th location
    {
        return fxn(board, i, j + 1);
    }
}

void solveSudoku(vector<vector<char> > &board)
{
    fxn(board, 0, 0);
}

int main()
{
    vector<vector<char> > board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);

    for (int k = 0; k < board.size(); k++)
        {
            for (int g = 0; g < board[k].size(); g++)
            {
                cout << board[k][g];
            }
            cout << endl;
        }

    return 0;
}