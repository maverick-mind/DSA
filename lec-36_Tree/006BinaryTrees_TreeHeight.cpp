/*

given the pre-order traversal of a binary tree, design a recursive
algorithm to find height of the tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1


*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


TreeNode * buildTree(vector<int> arr , int & i)
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
    root -> left = buildTree(arr , i);
    i++ ;
    root -> right = buildTree(arr , i);

    return root ;
}


void printPreOrder(TreeNode* root) {

	// base case
	if (!root) { // root == NULL
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process the root TreeNode
	cout << root->val << " ";

	// 2. do the preOrder traversal of the leftSubtree
	printPreOrder(root->left);

	// 3. do the preOrder traversal of the rightSubtree
	printPreOrder(root->right);

}

int dfs(TreeNode* root) {

	// base case

    // leaf node is at 0 height , so NULL node below leaf node is at -1 height 
	if (root == NULL) {
		return -1 ;
	}

    // recurrence relation 
    int heightLeft = dfs(root -> left) ;
    int heightRight = dfs(root -> right) ;

    return 1 + max( heightLeft , heightRight );

}

int main() {

    // preorder traversal is given 
    vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};

    int i = 0 ;
    TreeNode * root = buildTree(arr , i);

    cout<<"height of binary tree : " <<dfs(root)<<endl;
 
    printPreOrder(root);


	return 0;
}