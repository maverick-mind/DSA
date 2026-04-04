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

   //is current node a common ancestor , kya current node se P aur Q par pahuch sakte hai ?
bool icnaca(TreeNode* root, TreeNode* child)
{
    // base case 
    if(root == NULL)
    {
        return false ;
    }

    // recurrence relation 

    if(root == child) return true ;

    if(icnaca(root->left , child))
    {
        return true ; // agar root ke left se answer mill gya , no need to go to right
    }

    return icnaca(root->right , child); // go right only when root ke left se false milaa ho 

}


// we need 2 functions , one for traversing the tree , other for setting the current node as possible lowest common ancestor and check is it the LCA or not ?
TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // base case 
    if(root == NULL) return NULL ;

    // recursive case 
    
    TreeNode * ans = NULL ;
    TreeNode * temp = NULL ; 

    // check wether the current node could be a common ancestor or not 
    if(icnaca(root , p ) and icnaca(root , q ) ) // is current node 
    {                                   //  a common ancestor  of P and Q
        ans = root ; 
        temp = root ; 
        // now check if there exist any node in the left or right of current node , which is more nearer(lowest common ancestor) to node P and Q
        if(temp = dfs(root->left , p , q)) // if fxn returns NULL ,
        {               // it will not change value of ans ,
                 // that is why we are not writing ans = dfs(root->left , p , q)
            ans = temp ;
            return ans ; 
        }
        else if(temp = dfs(root->right , p , q))
        {
            ans = temp ;
            return ans; 
        }
    }
    return ans ; 

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    return dfs(root , p , q);

}
};