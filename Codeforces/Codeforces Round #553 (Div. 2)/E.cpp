#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 100010;

ll a[ maxn ];
int n;

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ) cin >> a[ i ];

    ll sum = 0;
    for( int i = 1; i <= n; i ++ )
    {
        if( a[ i ] == a[ i - 1 ] ) continue;
        if( a[ i ] > a[ i - 1 ] ) sum += ( a[ i ] - a[ i - 1 ] ) * ( n - a[ i ] + 1 );
        else                      sum += a[ i ] * ( a[ i - 1 ] - a[ i ] );
    }
    cout << sum << endl;
    return 0;
}