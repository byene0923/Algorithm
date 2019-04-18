#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll l, r;

ll a[ 63 ];


ll Calcu( ll x )
{
    ll pos = -1;
    ll tmp = x;
    for( int i = 0; i <= 62; i ++ )
    {
        if( a[ i ] <= tmp ) pos = i ,tmp -= a[ i ];
        else break;
    }
    if( pos == -1 ) return x;
    ll sum = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    for( int i = 0; i <= pos; i ++ ) sum += a[ i ];
    for( int i = 0; i <= pos; i += 2 ) sum1 += a[ i ];
    if( pos & 1 )
    {
        sum1 += ( x - sum );
        sum2 = x - sum1;
    }
    else sum2 = x - sum1;
    ll t1 = ( ( sum1 % mod * 2 % mod + ( sum1 % mod ) * ( ( sum1 - 1 ) % mod ) % mod ) % mod - sum1 % mod + mod ) % mod;
    ll t2 = ( sum2 % mod * 2 % mod + ( sum2 % mod ) * ( ( sum2 - 1 ) % mod ) % mod ) % mod;
    return ( t1 + t2 ) % mod;
}

int main()
{
    a[ 0 ] = 1;
    for( int i = 1; i <= 62; i ++ ) a[ i ] = a[ i - 1 ] * 2;
    cin >> l >> r;
    l --;
    cout << ( Calcu( r ) - Calcu( l ) + mod ) % mod << endl;
    return 0;
}