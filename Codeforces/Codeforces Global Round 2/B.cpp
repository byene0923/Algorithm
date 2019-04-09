#include <bits/stdc++.h>
using namespace std;

int n, h;
int a[ 1010 ];

priority_queue< int > q;

int Check( int x )
{
    while( !q.empty() ) q.pop();
    for( int i = 1; i <= x; i ++ ) q.push( a[ i ] );
    int hh = h;
    while( !q.empty() )
    {
        auto now = q.top();
        q.pop();
        if( hh < now ) return 0;
        hh -= now;
        if( !q.empty() ) q.pop();
    }
    return 1;
}

int main()
{
    cin >> n >> h;
    for( int i = 1; i <= n; i ++ ) cin >> a[ i ];
    int l = 1;
    int r = n;
    int goal = 1;
    while( l <= r )
    {
        int mid = l + r >> 1;
        if( Check( mid ) )
        {
            goal = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << goal << endl;
    return 0;
}