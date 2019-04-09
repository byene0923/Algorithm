class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector< bool > goal;
        int n = pattern.length();
        for( auto x: queries )
        {
            int cnt = 0;
            bool flag = true;
            for( auto y: x )
            {
                if( cnt < n && y == pattern[ cnt ] )
                {
                    cnt ++;
                    continue;
                }
                if( y >= 'A' && y <= 'Z' )
                {
                    flag = false;
                    break;
                }
            }
            if( cnt < n ) flag = false;
            goal.push_back( flag );
        }
        return goal;
    }
};