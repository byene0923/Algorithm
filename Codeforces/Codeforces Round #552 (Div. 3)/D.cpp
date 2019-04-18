#include<bits/stdc++.h>
using namespace std;

int n, b, a, A;
int s[ 200100 ];

int main()
{
    cin >> n >> b >> a;
    for( int i = 1; i <= n; i ++ ) cin >> s[ i ];
    A = a;
    int pos = 0;
    for( int i = 1; i <= n; i ++ )
    {
        if( s[ i ] == 1 )
        {
            if( a == A ) a --;
            else if( b )
            {
                b --;
                if( a < A ) a ++;
            }
            else if( a ) a --;
        }
        if( s[ i ] == 0 )
        {
            if( a ) a --;
            else if( b ) b --;
        }
        if( a == 0 && b == 0 )
        {
            pos = i;
            break;
        }
    }
    if( pos == 0 ) pos = n;
    cout << pos << endl;
    return 0;
}