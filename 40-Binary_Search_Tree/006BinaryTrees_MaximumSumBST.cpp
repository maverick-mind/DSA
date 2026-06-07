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

// took 10 minutes to realise , what attributes nodeInfo should have 
// took 33 minutes to code (24 minutes for the first time , 9 minutes to figure out after copy pasting 63rd line , in 64 line I did not update max to min)

/*
For a parent node to decide whether its subtree is a BST, it needs:
Is left subtree BST?
Is right subtree BST?
Maximum value in left subtree
Minimum value in right subtree
*/
class nodeInfo{

public :
    int sum = 0 ; 
    bool isBST ;
    int leftSeMax ;
    int rightSeMin ;
};

class Solution {
public:
int answerSum = 0 ; 

    nodeInfo dfs(TreeNode* root)
    {
        nodeInfo currentNode ;
        if(root == NULL)
        {
            currentNode.sum = 0;
            currentNode.isBST = true ; // an empty tree is a bst 
            currentNode.leftSeMax = INT_MIN ;
            currentNode.rightSeMin = INT_MAX;
            return currentNode;
        }


        // recurrence relation 

        nodeInfo leftSubtree = dfs(root->left);
        nodeInfo rightSubtree = dfs(root->right);

        // check if both leftSubtree and rightSubtree are BST or not
        // and if root follows bst property or not 
        // and accordingly , update sum , answerSum , isBST , leftSeMax , rightSeMin

        bool doesBstPropWorkAtRoot = root->val > leftSubtree.leftSeMax and root->val < rightSubtree.rightSeMin ;

        if((leftSubtree.isBST == true) and (rightSubtree.isBST == true) and doesBstPropWorkAtRoot)
        {
                currentNode.sum = root->val + leftSubtree.sum + rightSubtree.sum;
                currentNode.leftSeMax = max({root->val , leftSubtree.leftSeMax , rightSubtree.leftSeMax});
                currentNode.rightSeMin = min({root->val , leftSubtree.rightSeMin , rightSubtree.rightSeMin});
                answerSum = max(answerSum , currentNode.sum);
           
        }else{ // if either of leftSubtree or rightSubtre is not a BST or bst property fails at root node
                doesBstPropWorkAtRoot = false ; // bst prop will hold true only if it hold true at root , leftSubtree and rightSubtree
                currentNode.sum = 0 ;
                currentNode.leftSeMax = INT_MIN ;
                currentNode.rightSeMin = INT_MAX ;
        }
        currentNode.isBST = doesBstPropWorkAtRoot ;

        return currentNode ;
    }
    int maxSumBST(TreeNode* root) {
        answerSum  = 0 ;
        nodeInfo result = dfs(root);
        return answerSum ;
    }
};