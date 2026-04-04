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

//is current node a common ancestor , kya current node se P aur Q par pahuch sakte hai ?
bool icnaca(TreeNode* root, TreeNode* child)
{
    // base case 
    if(root == NULL)
    {
        return false ;
    }

    // recurrence relation 

    if(root == child) return true ;

    if(icnaca(root->left , child))
    {
        return true ; // agar root ke left se answer mill gya , no need to go to right
    }

    return icnaca(root->right , child); // go right only when root ke left se false milaa ho 

}


// we need 2 functions , one for traversing the tree , other for setting the current node as possible lowest common ancestor and check is it the LCA or not ?
TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // base case 
    if(root == NULL) return NULL ;

    // recursive case 
    
    TreeNode * ans = NULL ;
    TreeNode * temp = NULL ; 

    // check wether the current node could be a common ancestor or not 
    if(icnaca(root , p ) and icnaca(root , q ) ) // is current node 
    {                                   //  a common ancestor  of P and Q
        ans = root ; 
        temp = root ; 
        // now check if there exist any node in the left or right of current node , which is more nearer(lowest common ancestor) to node P and Q
        if(temp = dfs(root->left , p , q)) // if fxn returns NULL ,
        {               // it will not change value of ans ,
                 // that is why we are not writing ans = dfs(root->left , p , q)
            ans = temp ;
            return ans ; 
        }
        else if(temp = dfs(root->right , p , q))
        {
            ans = temp ;
            return ans; 
        }
    }
    return ans ; 

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    return dfs(root , p , q);

}

int main() 
{
    // preorder traversal is given 
    vector<int> arr = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};
    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl; 

    TreeNode* p1 = root->left ; // i.e. 5 
    TreeNode* q1 = root->right ; // i.e. 1 

    // lowestCommonAncestor(root , p1 , q1 );


    TreeNode* p2 = root->left->right->right ; // i.e. 4
    TreeNode* q2 = root->left ; // i.e. 5
    TreeNode* ans = lowestCommonAncestor(root , p2 , q2 ); // 5 ans 
    
    if(ans != NULL) cout<<ans->val<<endl;

    ans = lowestCommonAncestor(root , p1 , q1 ); // 3 ans 
    if(ans != NULL) cout<<ans->val<<endl;


    vector<int> arr1 = {37,-34,-1,-100,-1,-1,-48,-101,-1,-1,48,-54,-71,-1,-1,-22,-1,8,-1,-1,-1};
    i = 0 ;
    TreeNode * root1 = buildtreePreOrder(arr1 , i);

    TreeNode* p3 = root1->right->right->left->left ; // i.e. -71
    TreeNode* q3 = root1->right->right ; // i.e. 48

    printPreOrder(root1);
    cout<<endl; 
    ans = lowestCommonAncestor(root1 , p3 , q3 ); // 3 ans 
    if(ans != NULL) cout<<ans->val<<endl;

    return 0 ;
} 