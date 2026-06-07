/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

// time : O(h)

int findMinimum(TreeNode* root) { // to calculate minimum value in the right subtree 

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

// time : O(h)

int findMaximum(TreeNode* root) { // to calculate maximum value in the left subtree

	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

 // root ki value should be greater than all the nodes in the left subtree
// root ki value should be greater than all the nodes in the right subtree 

/*
            10      // root-> val > all the val in left subtree OR root->val > left se max
          /    \    // root->val < all the val in the right subtree 
         5     15   // OR root->val < right se min 
       /  \   /   \ 
      3   12 13   17
*/

// time : O(n^2)
bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// f(root) : check if the given tree is a BST

	// 1. ask your friend to check if the LST is a BST

	bool leftIsBST = checkBST(root->left);

	// 2. ask your friend to check if the RST is a BST

	bool rightIsBST = checkBST(root->right);

	// 3. check if the BST prop. works at the root node

	bool doesBSTPropWorkAtRoot = root->val > findMaximum(root->left) and
	                             root->val < findMinimum(root->right) ? true : false;

	return leftIsBST and rightIsBST and doesBSTPropWorkAtRoot;

}

class triple {
public:
	int leftSeMaxVal; // it is max of subtree at root node , naming convention is like this because , we compare root->val with max of left subtree 

	int rightSeMinVal; // it is min of subtree at root node , naming convention is like this because , we compare root->val with min of right subtree 
	bool isBST;
};

// time : O(n)

triple checkBSTOptimised(TreeNode* root) {

    triple t ;
    // base case 
    if(root == NULL)
    {
        t.leftSeMaxVal = INT_MIN ; 
        t.rightSeMinVal = INT_MAX ;
        t.isBST = true ;
        return t ;
    }

    // recurrence relation 
    // leftSubtree ka kaam friend karega 
    triple leftSubtree = checkBSTOptimised(root->left);

    // rightSubtree ka kaam friend karega 
    triple rightSubtree = checkBSTOptimised(root->right);

    // now check , does the BST property works at the root node 
    bool doesBSTPropWorkAtRoot = root->val > leftSubtree.leftSeMaxVal and 
                                 root->val < rightSubtree.rightSeMinVal ; 
    t.isBST = doesBSTPropWorkAtRoot ; 

    t.leftSeMaxVal = max(root->val , max(leftSubtree.leftSeMaxVal ,rightSubtree.leftSeMaxVal));

    t.rightSeMinVal = min(root->val , min(leftSubtree.rightSeMinVal ,rightSubtree.rightSeMinVal));

    return t ;
	
}

// time : O(n)
// every node in a BST must lie in a range
bool checkBSTOptimisedUsingRanges(TreeNode* root, long long lb, long long ub) {

	// base case 
    if(root == NULL){
        return true ;
    }

    // recurrence relation 

    bool doesBSTPropWorkAtRoot =  root->val > lb and root->val < ub ;


    // left subtree ke node ki range (lower bound , root->val) both exclusive (not using []square bracket , because the range is exclusive , not inclusive)
    bool leftSubtree = checkBSTOptimisedUsingRanges(root->left , lb , root->val);

    // right subtree ke nodes ki range (root->val , ub); 
    bool rightSubtree = checkBSTOptimisedUsingRanges(root->right , root->val , ub);
   
    return doesBSTPropWorkAtRoot and lefleftSubtree and rightSubtree ;
}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(6);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = checkBSTOptimised(root);

	t.isBST ? cout << "true" << endl : cout << "false" << endl;

	long long lb = INT_MIN - 1ll;
	long long ub = INT_MAX + 1ll;

	checkBSTOptimisedUsingRanges(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}