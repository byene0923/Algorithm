#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 200010;

struct node
{
    int l;
    int r;
}A[ maxn ];

int n, k, x;
int pos[ maxn ];
int ans[ maxn ];

vector< int > vec;

void rem( int ind )
{
    A[ A[ ind ].l ].r = A[ ind ].r;
    A[ A[ ind ].r ].l = A[ ind ].l;
}

int main()
{
    cin >> n >> k;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> x;
        A[ i ].l = i - 1;
        A[ i ].r = i + 1;
        pos[ x ] = i;
    }
    A[ n + 1 ].r = n + 1;
    A[ n + 1 ].l = n;
    A[ 0 ].r = 1;
    int team = 1 ;
    for( int i = n; i; i -- )
    {
        int ind = pos[ i ];
        if( ans[ ind ] ) continue;
        for( int j = 1, x = A[ ind ].l; j <= k && x != A[ x ].l; j ++, x = A[ x ].l ) vec.push_back( x );
        for( int j = 1, x = A[ ind ].r; j <= k && x != A[ x ].r; j ++, x = A[ x ].r ) vec.push_back( x );
        vec.push_back( ind );
        for( int x: vec )
        {
            rem( x );
            ans[ x ] = team;
        }
        vec.clear();
        team = 3 - team;
    }
    for( int i = 1; i <= n; i ++ ) cout << ans[ i ];
    cout << endl;
    return 0;
}