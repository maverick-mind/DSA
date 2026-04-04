// har node ka jo left-subtree hai , uss left-subtree ka jo rightmost node hai , uss node se hum chahte hai ki , hamaare current node tak ek link aaye , right most node ek aisaa node hai jisska right child exist nahi karta 

// for in-order , current node ko ans vector mein daalo and create a temporary variable temp to find right mose node of the left subtree , whose root is current , and after doing this then only move towards left by current = current -> left ;
// But if for a current as root node , in its left subtree the right most node is connected to the current(then delete the THREAD)

// and if current ka left dost not exist , move to right 


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

vector<int> preOrderMorris(TreeNode * root)
{
    vector<int>ans ;

    TreeNode * current = root ;
    while(current != NULL)
    {
        // before moving current->left , find the right most node of left-subtree(where root node of left-subtree is current) 
        TreeNode * temp = current -> left ;

        bool first_time = true ; // current aur left subtree ke right node mein link nahi banaa hai 

        while(temp != NULL and temp -> right != NULL)
        {

            if(temp -> right == current) // it means there already exist and to second visit detect
            {   // between right most node of left subtree , and current node
                // it means we are at current node for the second time and now we want to break the thread , which was earlier created 
                temp -> right = NULL ; // it means we are deleting the thread created by us 
                first_time = false ;
                break ;
            }
            temp = temp -> right ;
        }
        if(first_time and temp != NULL) temp -> right = current ;
        if(first_time) ans.push_back(current->val);
        if(current->left != NULL and first_time)
        {
          current = current -> left ;
        }
        else {
            current = current -> right ;
        }
    }
    return ans ;
}

int main() 
{
    // preorder traversal is given 
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};
    vector<int> arr = {0,1,3,6,-1,-1,7,-1,-1,4,-1,-1,2,-1,5,-1,-1};

    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl;
    vector<int>ans = preOrderMorris(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0 ;
}