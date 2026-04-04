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

    // Get child values (use a sentinel value for NULL children)
    int r1_left = (root1->left != NULL) ? root1->left->val : -1;
    int r1_right = (root1->right != NULL) ? root1->right->val : -1;
    int r2_left = (root2->left != NULL) ? root2->left->val : -1;
    int r2_right = (root2->right != NULL) ? root2->right->val : -1;

    
    // ek root pe 3 condition honge , 

    // 1. chid of root1 and root2 are equivalent : move to sub-child
     // only condition missing is : I am not checking whether , left child or right child is NULL before comparing it 
    if(r1_left == r2_left and r1_right == r2_right)// no swapping needed 
    {
         // Do nothing, proceed to recursion
    }

    // 2. child of root1 and root2 are inverted : mirror it then move sub child 
    else if(r1_left == r2_right and r1_right == r2_left)
    {
        swap(root1->left , root1->right);
    }
    // 3. any one child of root1 and root2 are different : return false , no need to further check 
    // if(r1_left != r2_left or r1_right != r2_right) // need to update r1_left,right and r2_left,right in choice 2 , if you want to use if statement , instead use if else if else 
    else
    {
        return false ; 
    }

    bool isLeftEquivalent = flipEquiv(root1->left , root2->left);
    bool isRightEquivalent = flipEquiv(root1->right , root2->right);
    
    return isLeftEquivalent && isRightEquivalent ;
}



// claude code 
// bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//     // Base cases
//     if(root1 == NULL && root2 == NULL) return true;
//     if(root1 == NULL || root2 == NULL) return false;
//     if(root1->val != root2->val) return false;  // Compare values, not pointers
    
//     // Get child values (use a sentinel value for NULL children)
//     int r1_left = (root1->left != NULL) ? root1->left->val : -1;
//     int r1_right = (root1->right != NULL) ? root1->right->val : -1;
//     int r2_left = (root2->left != NULL) ? root2->left->val : -1;
//     int r2_right = (root2->right != NULL) ? root2->right->val : -1;
    
//     // Case 1: Children already match - no swapping needed
//     if(r1_left == r2_left && r1_right == r2_right) {
//         // Do nothing, proceed to recursion
//     }
//     // Case 2: Children are inverted - swap them
//     else if(r1_left == r2_right && r1_right == r2_left) {
//         swap(root1->left, root1->right);
//     }
//     // Case 3: Children don't match either way - return false
//     else {
//         return false;
//     }
    
//     // Recurse on children
//     bool isLeftEquivalent = flipEquiv(root1->left, root2->left);
//     bool isRightEquivalent = flipEquiv(root1->right, root2->right);
    
//     return isLeftEquivalent && isRightEquivalent;
// }



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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // 2 possibilities at each node :
    // 1. flip kar ke equivalent ho jaayega
    // 2. bina flip kiye equivalent ho jaayega
    // agar dono se nahi hoga then , base case se return false kar do
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        // base case
        // we are never checking in this code ki root1 ki value root2 ke equal
        // hai ya nahi , we are checking ki kya root1 root 2 ke equal nahi hai
        // then return false , and we are maintaining conitions in such a way ki
        // root1 aur root2 ek hi time pe NULL ho , baically jab tak tree ke kisi
        // bhi node pe root_pointer hai , they must not be different , and
        // ensuring they hit NULL at the same time
        if (root1 == NULL and root2 == NULL)
            return true;
        if (root1 == NULL and root2 != NULL)
            return false;
        if (root1 != NULL and root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;

        // recurence relation

        // similar to inclusion exclusion principle
        bool check1 = false;
        bool check2 = false;

        // ek baar flip kar do
        swap(root1->left, root1->right);

        check1 = flipEquiv(root1->left, root2->left) and
                 flipEquiv(root1->right, root2->right);

        swap(root1->left, root1->right); // backtracking

        check2 = flipEquiv(root1->left, root2->left) and
                 flipEquiv(root1->right, root2->right);

        return check1 or check2;
    }
};