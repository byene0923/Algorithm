#include<bits/stdc++.h>
using namespace std;

int n, m, h;
int a[ 105 ];
int b[ 105 ];
int c[ 105 ][ 105 ];

int main()
{
    cin >> n >> m >> h;
    for( int i = 1; i <= m; i ++ ) cin >> a[ i ];
    for( int i = 1; i <= n; i ++ ) cin >> b[ i ];
    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ ) cin >> c[ i ][ j ];

    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ )
    {
        if( c[ i ][ j ] ) c[ i ][ j ] = a[ j ];
    }

    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ )
    {
        if( c[ i ][ j ] > b[ i ] ) c[ i ][ j ] = b[ i ];
    }

    for( int i = 1; i <= n; i ++ )
    {
        for( int j = 1; j <= m; j ++ ) cout << c[ i ][ j ] << " ";
        cout << endl;
    }

    return 0;

}
