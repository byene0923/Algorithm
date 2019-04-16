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
    stack< TreeNode* > sta;
    vector< pair< int, int > > node;
    unordered_map< TreeNode*, int > Index;
public:
    TreeNode* recoverFromPreorder(string S) {
        
        getNode( S );
        
        for( auto x: node )
        {
            int val = x.first;
            int dep = x.second;
            TreeNode* now = new TreeNode( val );
            Index[ now ] = dep;
            if( sta.empty() || Index[ sta.top() ] < dep )
            {
                if( sta.empty() )  sta.push( now );
                else
                {
                    auto pre = sta.top();
                    sta.pop();
                    if( pre->left == NULL ) pre->left = now;
                    else                    pre->right = now;
                    sta.push( pre );
                    sta.push( now );
                }
            }
            else
            {
                while( !sta.empty() && Index[ sta.top() ] >= dep ) sta.pop();
                auto pre = sta.top();
                sta.pop();
                if( pre->left == NULL ) pre->left = now;
                else                    pre->right = now;
                sta.push( pre );
                sta.push( now );
            }
        }
        while( sta.size() > 1 ) sta.pop();
        return sta.top();
    }
    
    void getNode( string S )
    {
        auto n = S.length();
        int cnt = 0;
        int val = 0;
        for( int i = 0; i < n; i ++ )
        {
            if( S[ i ] != '-' )  val = val * 10 + ( S[ i ] - '0' );
            else
            {
                if( val )
                {
                    node.push_back( { val, cnt } );
                    val = 0;
                    cnt = 0;
                }
                cnt ++;
            }
        }
        node.push_back( { val, cnt } );
    }
    
};