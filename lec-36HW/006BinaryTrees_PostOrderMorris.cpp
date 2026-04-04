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

void printPostOrder(TreeNode * root)
{
    // base case 
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    }

    // recurrence relation

    printPostOrder(root->left);

    printPostOrder(root->right);

    cout<<root->val<<" ";
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



vector<int> postOrderMorris(TreeNode * root)
{
    // travel : <root> <right> <left> and after ans vector is built , reverse it 
    vector<int>ans ;

    TreeNode * current = root ;
    while(current != NULL)
    {
        if(current -> right == NULL)
        {
            ans.push_back(current->val) ; 
            current = current -> left;
        }
        else{
            TreeNode * temp = current -> right ;

            while(temp -> left != NULL and temp -> left != current)
            {
                temp = temp -> left ;
            }
            // 2 ways to break while loop
            if(temp -> left == NULL)
            {   // add a thread
                ans.push_back(current->val);
                temp -> left = current ;
                current = current -> right ;
            }
            else{ // temp -> left == current
                // remove thread , also it means we are visiting current for the 2nd time
                temp -> left= NULL ; 
                current = current->left ;
            }
        }
    }
    reverse(ans.begin() , ans.end());
    return ans ;
}

int main() 
{
    // preorder traversal is given 
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};
    vector<int> arr = {0,1,3,6,-1,-1,7,-1,-1,4,-1,-1,2,-1,5,-1,-1};

    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPostOrder(root);
    cout<<endl;
    vector<int>ans = postOrderMorris(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0 ;
}