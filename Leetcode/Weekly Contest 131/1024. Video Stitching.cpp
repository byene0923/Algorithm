class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector< pair< int, int > > vp;
        for( auto x: clips ) vp.push_back( { x[ 0 ], x[ 1 ] } );
        sort( vp.begin(), vp.end() );
        int Start = 0;
        int pre = 0;
        int flag = 1;
        int cnt = 0;
        while( flag && pre < T )
        {
            flag = 0;
            for( auto x: vp )
            {
                if( x.first > Start ) continue;
                if( x.second > pre )
                {
                    flag = 1;
                    pre = x.second;
                }
            }
            if( flag ) cnt ++;
            Start = pre;
        }
        if( pre < T ) return -1;
        return cnt;
    }
};