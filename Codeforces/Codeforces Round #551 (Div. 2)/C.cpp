#include<bits/stdc++.h>
using namespace std;

string str;
int n;

int main()
{
    cin >> n;
    cin >> str;
    if( str[ 0 ] == ')' || str[ n - 1 ] == '(' || ( ( n & 1 ) == 1 ) )
    {
        cout << ":(" << endl;
        return 0;
    }
    int sum = 0;
    int sum1 = 0;
    for( auto x: str )
    {
        if( x == '(' ) sum ++;
        else if( x == ')' ) sum1 ++;
    }
    if( sum > n / 2 || sum1 > n / 2 )
    {
        cout << ":(" << endl;
        return 0;
    }
    for( int i = 0; i < n; i ++ )
    {
        if( str[ i ] == '?' )
        {
            if( sum < n / 2 )
            {
                sum ++;
                str[ i ] = '(';
            }
            else str[ i ] = ')';
        }
    }
    sum = 0;
    sum1 = 0;
    for( int i = 0; i < n; i ++ )
    {
        if( str[ i ] == '(' ) sum ++;
        if( str[ i ] == ')' )
        {
            sum1 ++;
            if( sum1 >= sum && i != n - 1 )
            {
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << str << endl;
    return 0;
}