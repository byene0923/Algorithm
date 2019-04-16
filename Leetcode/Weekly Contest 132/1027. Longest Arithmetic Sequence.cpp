class Solution {

private:
    unordered_map< int, unordered_map<int, int> > dp;
    
public:
    int longestArithSeqLength(vector<int>& A) {
        auto n = A.size();
        auto ans = 0;
        for( int i = 1; i < n; i ++ )
        {
            for( int j = 0; j < i; j ++ )
            {
                dp[ A[ i ] - A[ j ] ][ i ] = max( dp[ A[ i ] - A[ j ] ][ i ], dp[ A[ i ] - A[ j ] ][ j ] + 1 );
                ans = max( ans, dp[ A[ i ] - A[ j ] ][ i ] );
            }
        }
        return ans + 1;
    }
};