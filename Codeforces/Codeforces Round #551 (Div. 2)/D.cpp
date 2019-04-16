#include<bits/stdc++.h>
using namespace std;

const int maxn = 300100;

vector< int > Children[ maxn ];
int Status[ maxn ], dp[ maxn ];

int n, a;

void dfs( int root )
{
    if( Children[ root ].empty() )
    {
        dp[ root ] = 1;
        return;
    }
    int val1 = 1e9;
    int val2 = 0;
    for( auto x: Children[ root ] )
    {
        dfs( x );
        if( Status[ root ] )  val1 = min( val1, dp[ x ] );
        else                  val2 += dp[ x ];
    }
    if( Status[ root ] ) dp[ root ] = val1;
    else                 dp[ root ] = val2;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ) cin >> Status[ i ];
    for( int i = 2; i <= n; i ++ )
    {
        cin >> a;
        Children[ a ].push_back( i );
    }
    int k = 0;
    for( int i = 1; i <= n; i ++ ) if( Children[ i ].empty() ) k ++;
    dfs( 1 );
    cout << k + 1 - dp[ 1 ] << endl;
    return 0;
}