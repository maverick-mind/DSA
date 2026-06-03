#include<bits/stdc++.h>
using namespace std;
 
class TreeNode{

    public :
    int val ;
    TreeNode* left ;
    TreeNode* right ;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL ;
        this->right = NULL;
    }
};

// build tree from pre order
TreeNode* btfpo(const vector<int> & arr , int &i)
{

    // base case 
    if(i == arr.size()) return NULL;
    if(arr[i] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[i]);
    i++;
    root->left = btfpo(arr , i);
    i++;
    root->right = btfpo(arr , i);

    return root ;
}

void printPreOrder(TreeNode* root)
{
    // base case 
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    }

    cout<<root->val<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
pair<bool,int> isHeightBalanced(TreeNode* root)
{
    // base case 
    if(root == NULL)
    {
        return {true , -1}; // leaf node se niche height : -1
    }

    // recurrence relation
    
    // auto [isLeftSubtreeBalanced , LeftSubtreeHeight] = isHeightBalanced(root->left) ; 
    pair<bool,int> leftSubtree = isHeightBalanced(root->left) ;  

    // prune the remaining part of unexplored tree , if for current node it is false
    if(leftSubtree.first == false) 
      return {false , 0} ; // prune , // height doesn't matter, parent will also short-circuit


    pair<bool,int> rightSubtree = isHeightBalanced(root->right);
    
    if(rightSubtree.first == false)
        return {false , 0} ; // prune

    bool check = abs(leftSubtree.second - rightSubtree.second) <= 1 ;
    return {check , max(leftSubtree.second , rightSubtree.second)+1} ; 
}

// Sentinel value trick — encode "unbalanced" as height = -2
int isBalancedTree(TreeNode* root)
{
    // base case 
    if(root == NULL) return -1 ; 

    // recurrence relation 
    int left = isBalancedTree(root->left);
    if(left == -2) return -2 ; // prune

    int right = isBalancedTree(root->right);
    if(right == -2) return -2 ; // prune

    if(abs(left-right) >= 2) return -2 ; // unbalanced

    return max(left,right) + 1 ;
}
 
int main() 
{
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,15,-1,-1,-1};// false 
    vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};// true
    int i = 0 ;
    TreeNode* root = btfpo(arr, i);
    printPreOrder(root);

    pair<bool,int> tree = isHeightBalanced(root);
    cout<<endl<<tree.first<<" "<<tree.second<<endl;

    if(isBalancedTree(root))
    {
        cout<<"balanced"<<endl;
    }else{
        cout<<"not balanced"<<endl;
    }
 
 
 
    return 0 ;
}