/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*

   1.Inorder traversal of the bst is reverse format.
   2.just used this method and find the kth smallest element in bst.

    Time Complpexity:O(N)
    Space Complexity:(N)

 */
 class Solution {
     public:
         int count =0;  int out=0;
      void getElement(TreeNode*node, int k){
        if(node->left != nullptr){
            getElement(node->left, k);
        }
        count++;
        if(count == k){
            out = node->val;
            return;
        }
        if(node->right != nullptr){
            getElement(node->right, k);
        }
    }

   int kthSmallest(TreeNode* root, int k) {
        getElement(root, k);
        return out;
   }
};
