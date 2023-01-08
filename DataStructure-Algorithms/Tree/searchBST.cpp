Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []



class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
          if(root==NULL) return root; // not found then return 
          
            if(root->val==val) // matched exact value
              return root;

            if(root->val > val) // left call
            return searchBST(root->left,val);

            else if(root->val < val){ // right call
            return searchBST(root->right,val);
            }
            return root;
     }
    
}
