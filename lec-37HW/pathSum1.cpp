#include<bits/stdc++.h>
using namespace std;
 
class TreeNode{

public :
    int val ;
    TreeNode * left ;
    TreeNode * right ;

    TreeNode(int val)
    {
        this->val = val ;
        this->left = NULL ;
        this->right = NULL ;
    }
} ;

void printPreOrder(TreeNode * root)
{
    // base case 
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    }

    // recurrence relation

    // 1. process the root node

    cout<<root->val<<" ";

    // 2. ask your friend to print the preOrder of LST

    printPreOrder(root->left);

    // 3. ask your friend to print the preOrder of RST
    
    printPreOrder(root->right);
}

TreeNode * buildtreePreOrder(vector<int> arr , int & i)
{
    // base case 
    if(i == arr.size() )
    {
        return NULL;
    }

    // leaf-node case 
    if(arr[i] == -1)
    {
        return NULL ; 
    }

    // recurrence relation 

    // ith value will be the value of current root 
    TreeNode * root = new TreeNode(arr[i]);
    i++ ;
    root -> left = buildtreePreOrder(arr , i);
    i++ ;
    root -> right = buildtreePreOrder(arr , i);

    return root ;
}

bool fxn(TreeNode * root , int targetSum , int & currentSum)
{
    // base case 
    if(root == NULL)
    {
        return false ;
    }

    // recurrence relation 
    currentSum += root->val ; // current node apne left aur right dono path mein include hoga 

    if(root -> left == NULL and root->right == NULL) // leaf node 
    {
        if(currentSum == targetSum)
        {
            return true ; 
        }
    }

    bool x = fxn(root->left , targetSum , currentSum);// current node ko include karne ke baad usske left se agar path exist karega then true milega nahi to false 

    bool y = fxn(root->right , targetSum , currentSum);// current node ko include karne ke baad usske right se agar path exist karega then true milega nahi to false 

    currentSum -= root->val ; // current node se path usske left mein bhi bann sakta hai aur right mein bhi , jab dono path explore ho jaaye then backtrack

    return (x or y); // agar dono mein se kisi ek path ka answer true hai then return true 

}

/*
To prune :

Current node:
 ├─ Try left
 │   ├─ success? → STOP (prune)
 │   └─ fail → try right

*/

// to prune the remaining tree , once I found a path whose sum is equal to targetSum , use if-statement 
bool fxn2(TreeNode* root, int targetSum, int currentSum)
{
    if(root == NULL) return false;

    currentSum += root->val;

    // leaf node
    if(root->left == NULL && root->right == NULL)
    {
        return currentSum == targetSum;
    }

    // PRUNING: if left gives true, right won't be explored
    if(fxn2(root->left, targetSum, currentSum))
        return true;

    return fxn2(root->right, targetSum, currentSum);
}



bool hasPathSum(TreeNode* root, int targetSum)
{
    if(root == NULL)
    {
        return false ;
    }
    int currentSum = 0 ; 
    return fxn2(root , targetSum , currentSum);
}

int main() 
{
    // preorder traversal is given 
    vector<int> arr = {5,4,11,7,-1,-1,2,-1,-1,8,13,-1,-1,4,-1,1,-1,-1};
    int targetSum = 22;
    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl; 
    if(hasPathSum(root , targetSum))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    return 0 ;
} 