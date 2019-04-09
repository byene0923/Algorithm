#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[ 100100 ], b[ 100100 ], s[ 100100 ];
int n, m;

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ) cin >> a[ i ];
    sort( a + 1, a + n + 1 );
    for( int i = 1; i <= n - 1; i ++ ) b[ i ] = a[ i + 1 ] - a[ i ];
    sort( b + 1, b + n  );
    for( int i = 1; i <= n; i ++ ) s[ i ] = s[ i - 1 ] + b[ i ];
    cin >> m;
    while( m -- )
    {
        ll l, r;
        cin >> l >> r;
        ll t = r - l + 1;
        int pos = lower_bound( b + 1, b + n, t ) - b;
        ll ans = s[ pos - 1 ] + ( n - pos + 1LL ) * t;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}