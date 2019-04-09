#include <bits/stdc++.h>
using namespace std;

int a[ 505 ][ 505 ];
int b[ 505 ][ 505 ];

int col[ 505 ];
int mul[ 505 ];

int main()
{
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ ) cin >> a[ i ][ j ];

    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ ) cin >> b[ i ][ j ];

    for( int i = 1; i <= n; i ++ )
    for( int j = 1; j <= m; j ++ )
    {
        if( a[ i ][ j ] != b[ i ][ j ] )
        {
            col[ i ] ++;
            mul[ j ] ++;
        }
    }
    int flag = 1;
    for( int i = 1; i <= n; i ++ ) if( col[ i ] & 1 ) flag = 0;
    for( int i = 1; i <= m; i ++ ) if( mul[ i ] & 1 ) flag = 0;
    if( flag ) cout << "Yes" << endl;
    else       cout << "No"  << endl;
    return 0;
}