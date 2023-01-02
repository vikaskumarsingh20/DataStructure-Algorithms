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
class Solution {
public:
   
   TreeNode *Merge(TreeNode*root1 , TreeNode*root2){
       //base case
       if(!root1) return root2;
       if(!root2) return root1;

       root1->val += root2->val; //addition
       root1->left = Merge(root1->left ,root2->left);//left call
       root1->right = Merge(root1->right,root2->right); // right call
       return root1;
   }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = Merge(root1 , root2);
          return root;
    }
};