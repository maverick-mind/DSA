
// https://leetcode.com/problems/diameter-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// on leetcode , if initialising something globally , make sure to initialise it inside the main function of leetcode , other wise , leetcode uses the value of the global variable in (i-1)th testcase inside the ith testcase 
int ans = 0; // to track diameter of the tree

class Solution {
public:

    // int ans = 0; // to track diameter of the tree

    int dfs(TreeNode* root) {

        // base case

        if(root == NULL) {
            return -1;
        }

        // recursive case

        int leftHgt = dfs(root->left);
        int rightHgt = dfs(root->right);

        int lenOfLongestPathThroughRoot = leftHgt + rightHgt + 2;
        ans = max(ans, lenOfLongestPathThroughRoot);

        return 1 + max(leftHgt, rightHgt);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0 ; //for gloabl varibale , on leetcode , initialise it , because may be for multiple test case , program run karega , to jo puraane test case ka ans thaa , uss se it will start the new test case , and jiss se you will get wrong output 
        dfs(root);
        return ans;
    }
};