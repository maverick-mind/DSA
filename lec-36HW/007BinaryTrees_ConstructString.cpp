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

string tree2str(TreeNode* root) {
        
    // base case 
    if(root == NULL)
    {
        return "" ; // empty string 
    }

    // recurrence relation 
    string s = to_string(root -> val)  ;
    
    string left = tree2str(root->left);

    //if left child exists then [ root + '(' + left + ')'] 
    //and if left child does not exist and right child exists , then we have to put "()" in place of left child i.e [ root + '()'] 
    if(left != "" or (left == "" and root -> right != NULL))
    {
        s = s + '(' + left ;
        s += ')';
    }

    string right = tree2str(root -> right);
    if(right != "") // if right tree subtree exists , only then s + '(' + right + ')' 
    {
        s = s + '(' + right ;
        s += ')';
    }

    return s ;

}

int main() 
{
    // preorder traversal is given 
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};
    // vector<int> arr = {1,2,4,-1,-1,-1,3,-1,-1};
    vector<int> arr = {1,2,-1,4,-1,-1,3,-1,-1};


    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl;
    cout<<tree2str(root);
    return 0 ;
}