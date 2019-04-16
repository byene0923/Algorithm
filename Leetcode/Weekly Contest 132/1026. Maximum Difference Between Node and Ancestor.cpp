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
    int goal;
    
public:
    int maxAncestorDiff(TreeNode* root) {
        goal = -1;
        dfsMax( root );
        dfsMin( root );
        return goal;
    }

    int dfsMax( TreeNode* root )
    {
        if( root->left == NULL && root->right == NULL ) return root->val;
        int Max = -1;
        if( root->left != NULL ) Max = max( Max, dfsMax( root->left ) );
        if( root->right != NULL ) Max = max( Max, dfsMax( root->right ) );
        if( root->val < Max ) goal = max( goal, Max - root->val );
        return max( Max, root->val );
    }
    
    int dfsMin( TreeNode* root )
    {
        if( root->left == NULL && root->right == NULL ) return root->val;
        int Min = 100100;
        if( root->left != NULL ) Min = min( Min, dfsMin( root->left ) );
        if( root->right != NULL ) Min = min( Min, dfsMin( root->right ) );
        if( root->val > Min ) goal = max( goal, abs( Min - root->val ) );
        return min( root->val, Min );
    }
    
};