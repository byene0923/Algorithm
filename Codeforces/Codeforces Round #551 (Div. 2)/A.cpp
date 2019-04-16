#include<bits/stdc++.h>
using namespace std;

int n, t;

pair< int, int > p[ 105 ];
int Time[ 105 ];

int main()
{
    cin >> n >> t;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> p[ i ].first >> p[ i ].second;
        while( p[ i ].first < t )
        {
            p[ i ].first += p[ i ].second;
        }
        Time[ i ] = p[ i ].first;
    }
    int goal = 1;
    int sum = Time[ 1 ];
    for( int i = 2; i <= n; i ++ )
    {
        if( sum > Time[ i ] )
        {
            sum = Time[ i ];
            goal = i;
        }
    }
    cout << goal << endl;
}