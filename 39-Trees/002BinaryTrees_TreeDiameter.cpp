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

// <diameter , height>
pair<int,int> diameterOfTree(TreeNode* root)
{
    // base case 
    if(root == NULL)
    {
        return {0,-1};
    }

    // recurrence relation 
    pair<int,int> leftSubtree = diameterOfTree(root->left);
    pair<int,int> rightSubtree = diameterOfTree(root->right);

    int height = max(leftSubtree.second , rightSubtree.second) + 1 ;

    // int childDiameter = max(leftSubtree.first , rightSubtree.first) ;
    // int diameter = max(childDiameter , (leftSubtree.second + 1) + (rightSubtree.second + 1));

    // use curley braces to apply max on multiple values at once 
    int diameter = max({leftSubtree.first , rightSubtree.first , (leftSubtree.second + 1) + (rightSubtree.second + 1)});

    return {diameter , height};
}

// saare diameter nikaalo , and max of all those diameter would be the diameter of the tree , 
// and in all diameter , there would be one node jo peak node hoga uss diameter path mein , uss se upar height mein koi node nahi hoga 
int dia = 0 ; // to track the diameter 
int diameterOfTree2(TreeNode* root )
{
    // base case 
    if(root == NULL)
    {
        return -1 ;
    }

    // recurrence relation
    int leftSubtreeHeight = diameterOfTree2(root->left);
    int rightSubtreeHeight = diameterOfTree2(root->right);

    // considering current node as peak node for the diameter cnstructed through it 
    // now calculate and maintain or update diameter 
    int lengthOfLongestPathThroughThisNode = (leftSubtreeHeight + 1) + (rightSubtreeHeight + 1) ;
    dia = max(dia , lengthOfLongestPathThroughThisNode);

    return max(leftSubtreeHeight , rightSubtreeHeight) + 1 ;
}


int main() 
{
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,15,-1,-1,-1};// false 
    vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};// true
    int i = 0 ;
    TreeNode* root = btfpo(arr, i);
    printPreOrder(root);

    pair<int,int> diameter = diameterOfTree(root);
    cout<<endl<<diameter.second<<" "<<diameter.first<<endl;
    cout<<diameterOfTree2(root)<<" "<<dia<<endl;
 
    return 0 ;
}