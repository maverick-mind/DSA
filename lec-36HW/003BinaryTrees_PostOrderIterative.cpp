#include<bits/stdc++.h>
using namespace std;
 

//Morris traversal temporarily converts the tree into a threaded tree, one subtree at a time, never all at once.

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

vector<int> postorderTraversalIterative(TreeNode* root) {
    stack<pair<TreeNode* , int >> s ; // to store the current node , left pe iterate karte time , current ko stack mein daal denge , so that we will not loose access
    vector<int>ans ;
    TreeNode * current = root ;

    // when current pointer is NULL and stack is also empty then stop 
    while(current != NULL or !s.empty())
    {
  
        if(current != NULL)
        {
            s.push({current , 1}); // current ko loose na kar de , issliye store it first before going left 
            current = current -> left ; // do only if current != NULL , so if bracket here is necessary 
        }
        else if(current == NULL) // it means root ka left iterate ho gya 
        {   // hai , ab stack ke top pe jo hai usska left iterate 
            //karna hai aur right ko fir se stack mein daalna hai 
            
            // stack ke top mein NULL ko pop kar do pahle 
            // if(s.top().first == NULL)
            // {
            //     s.pop() ;
            // }
            if(!s.empty()){ 
                while(!s.empty() and s.top().second == 2)
                {
                     ans.push_back(s.top().first->val);
                     s.pop() ;
                }
                
                // current = s.top().first ;

                if(!s.empty() and s.top().second == 1 )
                {
                    s.top().second = 2 ;
                    current = s.top().first->right ; 
                } 
            }
        }
    }
    return ans ;
}

int main() 
{
    // preorder traversal is given 
    vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};

    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    cout<<"recursive print : ";
    printPostOrder(root);
    cout<<endl;
    vector<int>ans = postorderTraversalIterative(root);
    cout<<"iterative print :";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0 ;
}