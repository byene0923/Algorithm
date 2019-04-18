include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 100010;

int n;
pair< ll, ll > p[ maxn ];

bool cmp( pair< ll, ll > a, pair< ll, ll > b )
{
    ll vala = a.first - a.second;
    ll valb = b.first - b.second;
    return vala > valb;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ) cin >> p[ i ].first >> p[ i ].second;
    sort( p + 1, p + n + 1, cmp );

    ll sum = 0;
    for( int i = 1; i <= n; i ++ ) sum += ( p[ i ].second * n );
    for( int i = 1; i <= n; i ++ ) sum -= p[ i ].second;
    for( int i = 1; i <= n; i ++ ) sum += ( ( p[ i ].first - p[ i ].second ) * ( i - 1 ) );
    cout << sum << endl;
    return 0;
}