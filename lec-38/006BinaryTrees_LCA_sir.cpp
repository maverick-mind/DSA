// 3 possibilities
// if P and Q both lies in left subtree --> LCA would be in left subtree
// if P and Q both lies in right subtree --> LCA would be in right subtree
// if either of P and Q lies in left and other lies in right --> ROOT will be LCA

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // base case 
        if(root == NULL) return NULL;
        if(root == p || root == q) return root ;

        // recurrence relation

        // 3 cases :
        // 1. LCA(p,q) is in LEFT SUBTREE , if p and q are both in left SUBTREE
        TreeNode *left_lca = dfs(root -> left , p , q) ; 

        // 2. LCA(p,q) is in RIGHT SUBTREE , if p and q are both in RIGHT SUBTREE
        TreeNode *right_lca = dfs(root -> right , p , q) ; 

        // 3. LCA(p,q) is neither in LEFT nor in RIGHT SUBTREE ,
        // if either of (p,q) lies in LEFT SUBTREE and other lies in RIGHT SUBTREE , then ROOT is LCA

        if(left_lca != NULL and right_lca == NULL) // LCA is in the LEFT
        {
            return left_lca ;
        }
        else if(left_lca == NULL and right_lca != NULL) // LCA is in the RIGHT 
        {
            return right_lca ;
        }
        else if(left_lca != NULL and right_lca != NULL) // LCA is in the ROOT NODE
        {
            return root ;
        }

        // else if(left_lca == NULL and right_lca == NULL)
        else
        {
            return NULL ;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root , p , q);
    }
};