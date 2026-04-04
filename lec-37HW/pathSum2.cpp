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


void fxn(TreeNode * root , int targetSum , int currentSum , vector<vector<int>> & ans , vector<int> & temp)
{
    // base case 
    if(root == NULL)
    {
        return ;
    }

    // recurrence relation 
    currentSum += root -> val ; 
    temp.push_back(root->val);

    if(root -> left == NULL and root -> right == NULL)
    {
        if(currentSum == targetSum)
        {
            ans.push_back(temp);
        }
    }

    fxn(root->left , targetSum , currentSum , ans , temp);
    fxn(root->right , targetSum , currentSum , ans , temp);

    // currentSum and temp are not pass by refrence so , function call stack khatam hote jo current node add ya push hua hai , wo substract aur pop ho jaayega currentSum aur temp vector se respectively , so no need to do currentSUm -= root -> val ; temp.pop() , or to save some time pass temp vector by refrence so that in each function call , time is not wasted in copying temp 
    temp.pop_back() ; // as temp is passed by refrence  


}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    
    vector<vector<int>> ans ;

    // if (root == NULL) // same thing is being done in above function so no
        //                   // need to write it twice
        // {
        //     return ans;
        // }

    vector<int> temp ;
    fxn( root , targetSum , 0 , ans , temp);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return ans ;
}

int main() 
{
    // preorder traversal is given 
    vector<int> arr = {5,4,11,7,-1,-1,2,-1,-1,-1,8,13,-1,-1,4,5,-1,-1,1,-1,-1};
    vector<int> arr1 = {1,2,-1,-1,3,-1,-1};
    int targetSum = 22;
    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl; 
    pathSum(root , targetSum );

    return 0 ;
} 