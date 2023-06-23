
#include<bits/stdc++.h>
using namespace std;
/*
<aside>
💡 Question-1

Given a binary tree, your task is to find subtree with maximum sum in tree.

Examples:

Input1 :       

       1

     /   \

   2      3

  / \    / \

4   5  6   7

Output1 : 28

As all the tree elements are positive, the largest subtree sum is equal to sum of all tree elements.

</aside>
*/
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int func(Node* root, int& ans) {
        if(!root) return 0;
        
        int a=func(root->left,ans);
        int b=func(root->right,ans);
        
        ans=max(ans,a+b+root->data);
        return a+b+root->data;
}
int findLargestSubtreeSum(Node* root)
{
        int ans=INT_MIN;
        func(root,ans);
        return ans;
}


/*
<aside>
💡 Question-2

Construct the BST (Binary Search Tree) from its given level order traversal.

Example:

Input: arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}

Output: BST:

            7

         /    \

       4     12

     /  \     /

    3   6  8

   /    /     \

 1    5      10

</aside>
*/

Node* getNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* LevelOrder(Node* root, int data)
{
    if (root == NULL) {
        root = getNode(data);
        return root;
    }
    if (data <= root->data)
        root->left = LevelOrder(root->left, data);
    else
        root->right = LevelOrder(root->right, data);
    return root;
}
 
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node* root = NULL;
 
    for (int i = 0; i < n; i++)
        root = LevelOrder(root, arr[i]);
 
    return root;
}
void inorderTraversal(Node* root)
{
    if (!root)
        return;
 
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
// now from given input array construct the level order traversal for bst 



/*
<aside>
💡 Question-3

Given an array of size n. The problem is to check whether the given array can represent the level order traversal of a Binary Search Tree or not.

Examples:

Input1 : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}

Output1 : Yes

For the given arr[], the Binary Search Tree is:

            7

         /     \

       4        12

     /  \      /

    3    6    8

   /    /      \

 1    5          10

Input2 : arr[] = {11, 6, 13, 5, 12, 10}

Output2 : No

The given arr[] does not represent the level order traversal of a BST.

</aside>
*/

struct Nodeinfo
{
    int data;
    int min, max;
};

bool levelOrderIsOfBST(int arr[], int n)
{

    if (n == 0)
        return true;
    queue<Nodeinfo> q;
    int i=0;
    Nodeinfo newNode;
    newNode.data = arr[i++];
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
    while (i != n && !q.empty())       
    {
        Nodeinfo temp = q.front();
        q.pop();
        if (i < n && (arr[i] < temp.data &&
                     arr[i] > temp.min))
        {
            newNode.data = arr[i++];
            newNode.min = temp.min;
            newNode.max = temp.data;
            q.push(newNode);               
        }
        if (i < n && (arr[i] > temp.data &&
                      arr[i] < temp.max))
        {
            newNode.data = arr[i++];
            newNode.min = temp.data;
            newNode.max = temp.max;
            q.push(newNode);           
        }       
    }
    if (i == n)
        return true; 
    return false;       
}