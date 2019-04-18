#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e7 + 5;

int s[ maxn ];
vector< int > v[ maxn ];

int main()
{
    int n;
    cin >> n;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> s[ i ];
        if( v[ s[ i ] ].size() < 2 ) v[ s[ i ] ].push_back( i );
    }

    ll goal = 1e18;
    int goall = 0;
    int goalr = 0;

    for( int gc = 1; gc <= 10000000; gc ++ )
    {
        int a = 0, b = 0;
        for( int j = gc; j <= 10000000; j += gc )
        {
            ll sz = v[ j ].size();
            for( auto x: v[ j ] )
            {
                if( a == 0 ) a = x;
                else if( b == 0 ) b = x;
            }
            if( b ) break;
        }
        if( !b ) continue;
        if( goal > s[ a ] * 1LL * s[ b ] / gc )
        {
            goal = s[ a ] * 1LL * s[ b ] / gc;
            goall = a;
            goalr = b;
        }
    }
    if( goall > goalr )
    {
        goall ^= goalr;
        goalr ^= goall;
        goall ^= goalr;
    }
    cout << goall << " " << goalr << endl;
    return 0;
}