#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 200100;

ll n, m, k, p, q;
ll a[ maxn ], sum[ maxn ];
ll dp[ 2020 ];

map< ll, ll > Index;

int main()
{
    cin >> n >> m >> k;
    for( int i = 1; i <= n; i ++ ) cin >> a[ i ];
    for( int i = 1; i <= m; i ++ )
    {
        cin >> p >> q;
        Index[ p ] = max( Index[ p ], q );
    }
    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= k; i ++ ) sum[ i ] = sum[ i - 1 ] + a[ i ];

    for( int i = 1; i <= k; i ++ ) dp[ i ] = dp[ i - 1 ] + a[ i ];

    for( int i = 1; i <= k; i ++ )
    {
        for( int j = 0; j <= i; j ++ )
        {
            if( Index[ i - j ] ) dp[ i ] = min( dp[ i ], dp[ j ] + sum[ i ] - sum[ j + Index[ i - j ] ] );
        }
    }
    cout << dp[ k ] << endl;
    return 0;
}
