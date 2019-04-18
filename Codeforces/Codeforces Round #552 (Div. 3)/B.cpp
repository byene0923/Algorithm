#include<bits/stdc++.h>
using namespace std;

int n;
int a[ 105 ];

int Check( int val, int s )
{
    for( int i = 2; i <= n; i ++ )
    {
        if( a[ i ] != s && a[ i ] + val != s && a[ i ] - val != s ) return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ) cin >> a[ i ];
    sort( a + 1, a + n + 1 );
    int goal = -1;
    for( int i = a[ 1 ]; i <= a[ n ]; i ++ )
    {
        int val =  i - a[ 1 ];
        if( Check( val, i ) )
        {
            goal = val;
            break;
        }
    }
    cout << goal << endl;
}
