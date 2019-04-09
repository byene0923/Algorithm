#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[ 300100 ];

int main()
{
    int n;
    ll goal = 0;
    ll unused = 0;
    cin >> n;
    for( int i = 1; i <= n; i ++ ) cin >> a[ i ];
    for( int i = 1; i <= n; i ++ )
    {
        if( i == 1 )
        {
            goal += a[ i ] / 3;
            unused += ( a[ i ] % 3 );
        }
        else
        {
            if( unused > a[ i ] / 2 )
            {
                unused -= a[ i ] / 2;
                goal += a[ i ] / 2;
                unused += ( a[ i ] % 2 );
            }
            else
            {
                goal += unused;
                a[ i ] -= unused * 2;
                unused = 0;
                goal += ( a[ i ] / 3 );
                unused += ( a[ i ] % 3 );
            }
        }
        //cout << goal << endl;
    }
    cout << goal << endl;
    return 0;
}