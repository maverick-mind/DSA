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


bool flag = false ; 
// path from root to taget node
void pfrttn(TreeNode * root , int targetNode , vector<int> temp , vector<vector<int>> & ans)
{
    // base case 
    if(root == NULL)
    {
        return  ; 
    }
    
    // recurrence relation 
    temp.push_back(root->val);
    if(root->val == targetNode)
    {
        ans.push_back(temp) ; 
        // temp.pop_back() ;
        flag = true ;  // 
    }

    // just in-case , if we want only the first path , and prune the remaining tree 
    // if(flag == true) // agar left se path mill gya then , and we want only 1 path 
    // {                // left ke niche koi path nahi dhundna hai 
    //                  // and right mein jaani ki zarurat nahi hai 
    //     return ; 
    // }

    pfrttn(root ->left , targetNode , temp , ans);

    pfrttn(root ->right , targetNode , temp , ans);
    temp.pop_back() ;


}

int main() 
{
    // preorder traversal is given 
    vector<int> arr = {2,7,3,1,3,-1,-1,9,-1,-1,8,-1,-1,6,4,-1,-1,3,-1,-1};
    int targetNode = 3; // this question assumes , no duplicate node exists in the tree
    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl; 

    vector<vector<int>> ans ; 
    vector<int> temp ; 

    pfrttn(root , targetNode , temp , ans );

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
  

    return 0 ;
} 