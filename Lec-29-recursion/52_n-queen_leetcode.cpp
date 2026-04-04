class Solution {
public:
    bool canBePlaced(vector<string>& board, int n, int i, int j) {
        // check the current column till now , if there exists any queen already
        for (int k = 0; k < i; k++) {
            if (board[k][j] == 'Q')
                return false;
        }

        // check the left diagonal
        int row = i, col = j;
        while (row >= 0 and col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // check the right diagonal
        row = i, col = j;
        while (row >= 0 and col < n) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col++;
        }

        return true;
    }

    void fxn(vector<string>& board, int n, int i, int j,
             int & ans) {

        // base case
        if (i >= n) {
            ans++;
            return;
        }
        if (j >= n)
            return;

        // recurrence relation

        // can we put a queen at (i,j) as to canBePlaced function
        if (canBePlaced(board, n, i,
                        j)) // if this fxn returns true , then we can place
        {
            board[i][j] = 'Q';
            // now move onto the next row , and start looking places from the
            // starting column
            fxn(board, n, i + 1, 0, ans);

            board[i][j] = '.';
        }

        // else condition se trouble ho sakta hai
        // else{
        // You explored the next column only when placement failed.
        // But if placement succeeded, you never checked the next column in that
        // same row — missing valid configurations.
        //      fxn(board , n , i , j + 1 );

        // }

        // even after placing the queen on (i,j) , check for further more
        // possibilities , in the same row at different columns location
        fxn(board, n, i, j + 1, ans);
    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board;
        for (int i = 0; i < n; i++) {
            board.push_back(string(n, '.'));
        }
        fxn(board, n, 0, 0, ans);

        return ans;
    }
};