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

int countPath(TreeNode* root , int targetSum)
{
    // base case 
    if(root == NULL)
    {
        return 0 ; 
    }

    // recursive case 
   int count = 0 ;

    if(root->val == targetSum) // agar path root pe shuru aur root pe khatam , 
    {                   // then count++; but root pe hi shuru ho ke left ya right
                        // mein bhi path ho sakte hai , so also check left and right ,
                        //      for ex : 2         and target is 2 
                        //              /  \
                        //             0    2
        count++ ;//it has 2 path where pathSum is equal to targetSum : 2 , (2,0)
    }

    count += countPath(root->left , targetSum - root->val) ; // check path in the left of root including root
    count += countPath(root->right , targetSum - root->val) ; // check path in the right of root including root

    
    return count ; 
}

int main() 
{
    // preorder traversal is given 
    vector<int> arr = {2,7,3,1,-1,-1,8,-1,-1,3,-1,-1,6,4,-1,-1,5,-1,-1}; 
    vector<int> arr1 = {2,-3,3,1,-1,-1,8,-1,-1,3,-1,-1,6,4,-1,-1,2,-1,-1}; 
    int targetSum1 = 2 ;

    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl; 
    int targetSum = 12;
    cout<<countPath(root , targetSum)<<endl;
   

    return 0 ;
} 