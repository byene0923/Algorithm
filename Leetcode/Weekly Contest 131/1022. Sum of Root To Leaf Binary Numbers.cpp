/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

private:
    long long goal = 0;
    long long mod = 1e9 + 7;
    
public:
    int sumRootToLeaf(TreeNode* root) {
        if( root == NULL ) return 0;
        dfs( root, 0LL );
        return goal;
    }
    
    void dfs( TreeNode* root, long long sum )
    {
        int val = root->val;
        if( root->left == NULL && root->right == NULL )
        {
            goal = ( goal + sum * 2 + val ) % mod;
            return;
        }
        if( root->left != NULL )  dfs( root->left, ( sum * 2 + val ) % mod );
        if( root->right != NULL ) dfs( root->right, ( sum * 2 + val ) % mod );
    }
    
};