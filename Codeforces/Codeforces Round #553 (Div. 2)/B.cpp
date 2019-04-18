#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[ 505 ][ 505 ];
vector< int > v[ 11 ];
int path[ 505 ];

int main()
{
    cin >> n >> m;
    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ ) cin >> a[ i ][ j ];

    int flag = 0;
    int x = 0;
    int y = 0;
    for( int i = 0; i <= 10; i ++ )
    {
        if( flag ) break;
        for( int j = 1; j <= n; j ++ )
        {
            if( flag ) break;
            int sum = 0;
            for( int k = 1; k <= m; k ++ )
            {
                sum += ( ( a[ j ][ k ] >> i ) & 1 );
            }
            if( sum == m ) v[ i ].push_back( j );
            else if( sum > 0 )
            {
                flag = 1;
                x = i;
                y = j;
                break;
            }
        }
    }
    if( flag )
    {
        cout << "TAK" << endl;
        int cnt = 0;
        for( int i = 1; i <= n; i ++ )
        {
            if( i != y )
            {
                cnt ^= ( ( a[ i ][ 1 ] >> x ) & 1 );
                path[ i ] = 1;
            }
        }
        for( int i = 1; i <= m; i ++ )
        {
            if( ( ( a[ y ][ i ] >> x ) & 1 ) != cnt )
            {
                path[ y ] = i;
                break;
            }
        }
        for( int i = 1; i <= n; i ++ ) cout << path[ i ] << " ";
        cout << endl;
    }
    else
    {
        for( int i = 0; i <= 10; i ++ )
        {
            if( v[ i ].empty() ) continue;
            int sz = v[ i ].size();
            if( sz & 1 )
            {
                flag = 1;
                cout << "TAK" << endl;
                for( int i = 1; i <= n; i ++ ) cout << 1 << " ";
                break;
            }
        }
        if( !flag ) cout << "NIE" << endl;
    }
}