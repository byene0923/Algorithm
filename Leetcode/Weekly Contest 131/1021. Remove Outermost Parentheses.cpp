class Solution {
public:
    string removeOuterParentheses(string S) {
        if( S.empty() ) return S;
        auto n = S.length();
        auto flag = 0;
        string goal;
        int cnt = 0;
        for( auto x: S )
        {
            if( flag == 0 )
            {
                flag = 1;
                cnt ++;
            }
            else
            {
                if( x == '(' ) cnt ++;
                else           cnt --;
                if( cnt != 0 ) goal += x;
                else           flag = 0;
            }
        }
        return goal;
    }
};