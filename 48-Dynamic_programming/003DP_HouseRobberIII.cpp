#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}

}

TreeNode* buildTreeFromLevelOrder(const vector<int> & input)
{
     TreeNode* curr  ;
    if(input[0] != -1)
    {
        curr = new TreeNode(input[0]);
    }else{
        return 0 ; 
    }


    queue<TreeNode*> q ;
    q.push(curr);
    

    // i = 1 starting because , the 0th index is pushed above in the queue
    for(int i = 1 ; i < input.size() ;) 
    {
        // jaise tree ka part banee , push it in queue , to process it's child 
        TreeNode* root = q.front();
        q.pop() ; 

        // left child 
        if(i < input.size() and input[i] != -1)
        {
            TreeNode* leftChild = new TreeNode(input[i]);
            root->left = leftChild ; 
            q.push(leftChild);
            i++;
        }else{
            root->left = NULL ;
            i++;
        }

        // right child 
        if(i < input.size() and input[i] != -1)
        {
            TreeNode* rightChild = new TreeNode(input[i]);
            root->right= rightChild ; 
            q.push(rightChild);
            i++;
        }else{
            root->right = NULL ;
            i++;
        }
    }

    return curr ; 
}


class nodeInfo{

public :
    int maxWealthCreatedIncludingCurrentNodeHouse ;
    int maxWealthCreatedEXcludingCurrentNodeHouse ;

};

// when we include current node we need to go root->child->child
// when we exclude current node we need to go to root->child
// with only recursion , we might go again to root->child->child from
// root->child by excluding root->child so clearly there is overlapping
// subproblem , to overcome this , maintain nodeInfo which stores wealth
// created by excluding and including current node
nodeInfo fxnTopDown(TreeNode* root) {
    nodeInfo node;
    // base case
    if (root == NULL) {
        node.maxWealthCreatedIncludingCurrentNodeHouse = 0;
        node.maxWealthCreatedEXcludingCurrentNodeHouse = 0;
        return node;
    }

    // recurrence relation
    nodeInfo leftSubtree = fxnTopDown(root->left);
    nodeInfo rightSubtree = fxnTopDown(root->right);

    node.maxWealthCreatedIncludingCurrentNodeHouse =
        root->val + leftSubtree.maxWealthCreatedEXcludingCurrentNodeHouse +
        rightSubtree.maxWealthCreatedEXcludingCurrentNodeHouse;

    // node.maxWealthCreatedEXcludingCurrentNodeHouse =
    //                     max({leftSubtree.maxWealthCreatedIncludingCurrentNodeHouse
    //                     +
    //                     rightSubtree.maxWealthCreatedIncludingCurrentNodeHouse
    //                     ,

    //                     leftSubtree.maxWealthCreatedEXcludingCurrentNodeHouse
    //                     +
    //                     rightSubtree.maxWealthCreatedEXcludingCurrentNodeHouse
    //                     ,

    //                     leftSubtree.maxWealthCreatedIncludingCurrentNodeHouse
    //                     +
    //                     rightSubtree.maxWealthCreatedEXcludingCurrentNodeHouse
    //                     ,

    //                      leftSubtree.maxWealthCreatedEXcludingCurrentNodeHouse
    //                      +
    //                     rightSubtree.maxWealthCreatedIncludingCurrentNodeHouse
    //                     }) ;
    // above is as same as

    // when excluding current node,
    // the child can be either included or excluded, so you should take the
    // max:
    node.maxWealthCreatedEXcludingCurrentNodeHouse =
        max(leftSubtree.maxWealthCreatedIncludingCurrentNodeHouse,
            leftSubtree.maxWealthCreatedEXcludingCurrentNodeHouse) +
        max(rightSubtree.maxWealthCreatedIncludingCurrentNodeHouse,
            rightSubtree.maxWealthCreatedEXcludingCurrentNodeHouse);

return node;
}

int rob(TreeNode* root) {
    nodeInfo node = fxnTopDown(root);
    return max(node.maxWealthCreatedIncludingCurrentNodeHouse , 
               node.maxWealthCreatedEXcludingCurrentNodeHouse);
}

int main()
{
    // vector<int> input = {10, 20, 30, 40, 50, -1, 60, -1, -1, 70, -1, -1, -1, -1, -1};
    vector<int> input = {3,4,5,1,3,-1,1};
    TreeNode* root = buildTreeFromLevelOrder(input);
    printLevelOrder(root);

    cout<<"maximum wealth robbed : "<<rob(root)<<endl;

    return 0;
}