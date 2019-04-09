#include <bits/stdc++.h>
using namespace std;

int a[ 300100 ];
int n;

int main()
{
    cin >> n;
    int Max = -1;
    for( int i = 1; i <= n; i ++ )  cin >> a[ i ];
    for( int i = 2; i <= n; i ++ )
    {
        if( a[ i ] != a[ 1 ] ) Max = max( Max, i - 1 );
    }
    for( int i = n - 1; i >= 1; i -- )
    {
        if( a[ i ] != a[ n ] ) Max = max( Max, n - i );
    }
    cout << Max << endl;
    return 0;
}