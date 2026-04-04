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

void printInOrder(TreeNode * root)
{
    // base case 
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    }

    // recurrence relation

    printInOrder(root->left);

    cout<<root->val<<" ";

    printInOrder(root->right);
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

vector<int> inOrderMorris(TreeNode * root)
{
   
    vector<int>ans ;

    TreeNode * current = root ;
    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            ans.push_back(current->val) ; 
            current = current -> right ;
        }
        else{
            TreeNode * temp = current -> left ;

            while(temp -> right != NULL and temp -> right != current)
            {
                temp = temp -> right ;
            }
            // 2 ways to break while loop
            if(temp -> right == NULL)
            {   // add a thread
                temp -> right = current ;
                current = current -> left ;
            }
            else{ // temp -> right == current
                // remove thread , also it means we are visiting current for the 2nd time
                ans.push_back(current->val);
                temp -> right = NULL ; 
                current = current->right ;
            }
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
 
    printInOrder(root);
    cout<<endl;
    vector<int>ans = inOrderMorris(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0 ;
}