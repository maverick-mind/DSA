#include<bits/stdc++.h>
using namespace std;
 
class TreeNode{

    public :
    int val ;
    TreeNode* left ;
    TreeNode* right ;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL ;
        this->right = NULL;
    }
};

// build tree from pre order
TreeNode* btfpo(const vector<int> & arr , int &i)
{

    // base case 
    if(i == arr.size()) return NULL;
    if(arr[i] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[i]);
    i++;
    root->left = btfpo(arr , i);
    i++;
    root->right = btfpo(arr , i);

    return root ;
}

void printPreOrder(TreeNode* root)
{
    // base case 
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    }

    cout<<root->val<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

class Triple{
    public :
        bool isUnderSurvilence ; 
        bool isCameraPlaced ; 
        int cameraCount ;
} ;
// <<isUnderSurvilence , isCameraPlaced> , cameraCount> 
Triple minCameras(TreeNode* root)
{
    Triple t ; 
    // base case
    if(root == NULL)
    {
        t.isUnderSurvilence = true ;
        t.isCameraPlaced = false ;
        t.cameraCount = 0 ;
        return t; // no need to put camera when tree is empty
    }

    // recurrence relation

    Triple leftSubtree = minCameras(root->left);
    Triple rightSubtree = minCameras(root->right);

    bool isCameraPlacedOnCurrentNode = false ;
    bool isCurrentNodeUnderServilence = false ;
    int cameraCountSoFar = leftSubtree.cameraCount + rightSubtree.cameraCount ;


    // case 1. if either of child is not under survilence , then put camera on the current node
    if(leftSubtree.isUnderSurvilence == false or rightSubtree.isUnderSurvilence == false)
    {// put camera on the current node 
        isCameraPlacedOnCurrentNode = true ;
        isCurrentNodeUnderServilence = true ;
        // make it true , and camera count should increase by 1 
        cameraCountSoFar += 1 ;
    }

    // if both left and right childen is under survilence by their respective any of their children , no need to put camera on the current parent node 
    // case 2. no camera on left and right subtree , but both are under survilence 
    else if((leftSubtree.isCameraPlaced == false and rightSubtree.isCameraPlaced == false) and  (leftSubtree.isUnderSurvilence == true and rightSubtree.isUnderSurvilence == true))
    {
        isCurrentNodeUnderServilence = false ;
    }
    
    // if camera is present on either of the child node , then the current parent node is also under survilence 
    // case 3. camera is either on left subtree or right subtree
    else if(leftSubtree.isCameraPlaced == true or rightSubtree.isCameraPlaced == true)
    {
        isCurrentNodeUnderServilence = true ;
    }

    t.isUnderSurvilence = isCurrentNodeUnderServilence  ;
    t.isCameraPlaced = isCameraPlacedOnCurrentNode ;
    t.cameraCount = cameraCountSoFar ;
    return t;

}

 
int main() 
{
    // vector<int> arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1};// 3
    // vector<int> arr = {10,20,40,-1,-1,50,-1,-1,30,-1,60,-1,-1};//2
    // vector<int> arr = {10,20,30,40,-1,-1,-1,-1,-1};//2
    // vector<int> arr = {10,20,-1,30,40,-1,50,60,-1,-1,-1,-1,-1};//2
    vector<int> arr = {10,-1,20,-1,30,-1,40,-1,-1};//2
    int i = 0 ;
    TreeNode* root = btfpo(arr, i);
    printPreOrder(root);

    Triple camera = minCameras(root);
    if(camera.isUnderSurvilence == false) camera.cameraCount++;
    cout<<endl<<camera.cameraCount<<endl;
 
 
    return 0 ;
}