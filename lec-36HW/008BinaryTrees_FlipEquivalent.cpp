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

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    // tree1 ko modify karenge sirf , tree2 bass compare karne ke liye hai 
    // base case 
    if(root1 == NULL and root2 == NULL)
    {
        return true ;
    }
    if(root1 == NULL and root2 != NULL) return false ;
    if(root1 != NULL and root2 == NULL) return false ;

    // recurrence relation 

   
    if(root1->val != root2->val) return false ; // left ya right child tab hi check karenge agar root same ho pahle 

    // agar left se true aaye aur right se true aaye , then return true 
    
    // ek root pe 3 condition honge , 

    // 1. chid of root1 and root2 are equivalent : move to sub-child
     // only condition missing is : I am not checking whether , left child or right child is NULL before comparing it 
    if(root1->left->val == root2->left->val and root1->right->val == root2->right->val)// no swapping needed 


    // 2. child of root1 and root2 are inverted : mirror it then move sub child 
    if(root1->left->val == root2->right->val and root1->right->val == root2->left->val)
    {
        swap(root1->left , root1->right);
    }
    // 3. any one child of root1 and root2 are different : return false , no need to further check 
    if(root1->left->val != root2->left->val or root1->right->val != root2->right->val)
    {
        return false ; 
    }
    bool isLeftEquivalent = flipEquiv(root1->left , root2->left);
    bool isRightEquivalent = flipEquiv(root1->right , root2->right);
    
    return isLeftEquivalent && isRightEquivalent ;
}


int main() 
{
    // preorder traversal is given 
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};
    // vector<int> arr = {1,2,4,-1,-1,-1,3,-1,-1};
    vector<int> arr1 = {1,2,4,-1,-1,5,7,-1,-1,8,-1,-1,3,6,-1,-1,-1};
    vector<int>arr2 = {1,3,-1,6,-1,-1,2,4,-1,-1,5,8,-1,-1,7,-1,-1};


    int i = 0 ;
    int j = 0 ;
    TreeNode * root1 = buildtreePreOrder(arr1 , i);
    TreeNode * root2 = buildtreePreOrder(arr2 , j);
 
    printPreOrder(root1);
    cout<<endl;
    printPreOrder(root2);
    
    // flipEquiv(root1 , root2) ? cout<<"true"<<endl : cout<<"false"<<endl ;
   if(flipEquiv(root1 , root2))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0 ;
}