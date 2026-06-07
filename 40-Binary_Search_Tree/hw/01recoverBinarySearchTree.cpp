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
class Solution {
public:
    // for O(1) extra space solution : use morris traversal 
    
    // this solution : O(n) extra space due to recursion stack 
    // travel in-order , you will find the node placed wrong , just swap it such that , the in-order of bst becomes sorted order 
TreeNode* wronglyPlacedNode1 = NULL ; // while inorder wrong position , previousInOrder will be stored into it 
TreeNode* wronglyPlacedNode2 = NULL ; // while inorder wrong position , root will be stored into it  
// for adjacent swaped nodes , while traversing in-Order , only one wrongly placed node will be found , so when for the first time wronglyPlacedNode found , initialise wronglyPlacedNode2 with root 
// also , the first wrongly placed node will be previousInOrder while comparison  
// secod wrongly placed node will be root while comparison
TreeNode* previousInOrder = NULL ; 
    void dfs(TreeNode* root )
    {
        if(root == NULL) return ;


        // recurrence relation 
        dfs(root->left);
        if(previousInOrder != NULL)
        {
            if((root->val < previousInOrder->val)) 
            {
                if(wronglyPlacedNode1 == NULL)
                {
                    wronglyPlacedNode1 = previousInOrder ; // we find the wrong positioned node
                    wronglyPlacedNode2 = root ; // In some cases like adjacent swapped nodes there's only one violation , so initialize wronglyPlacedNode2 = root at the first violation itself, and if a second violation is found, update it.
                }else{
                    wronglyPlacedNode2 = root ;
                }
            }
        }
        previousInOrder = root ; 
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(wronglyPlacedNode1->val , wronglyPlacedNode2->val);
    }
};