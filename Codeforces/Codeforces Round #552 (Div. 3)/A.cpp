#include<bits/stdc++.h>
using namespace std;

vector< int > v;

int main()
{
    for( int i = 0; i < 4; i ++ )
    {
        int a;
        cin >> a;
        v.push_back( a );
    }
    sort( v.begin(), v.end(), greater< int >{} );

    int A, B, C;
    A = v[ 0 ] - v[ 1 ];
    B = v[ 0 ] - v[ 2 ];
    C = v[ 0 ] - v[ 3 ];
    cout << A << " " << B  << " " << C << endl;
    return 0;
}