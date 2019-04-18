#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b, c;
ll A, B, C;

int Judge( int num, ll sum )
{
    if( sum == 0 ) return 1;
    for( int i = num; i <= 7; i ++ )
    {
        if( i == 1 || i == 4 || i == 7 ) A --;
        if( i == 2 || i == 6 ) B --;
        if( i == 3 || i == 5 ) C --;
        if( A < 0 || B < 0 || C < 0 ) return 0;
        sum --;
        if( sum == 0 ) return 1;
    }

    for( int i = 1; i < num; i ++ )
    {
        if( i == 1 || i == 4 || i == 7 ) A --;
        if( i == 2 || i == 6 ) B --;
        if( i == 3 || i == 5 ) C --;
        if( A < 0 || B < 0 || C < 0 ) return 0;
        sum --;
        if( sum == 0 ) return 1;
    }

    for( int i = num; i <= 7; i ++ )
    {
        if( i == 1 || i == 4 || i == 7 ) A --;
        if( i == 2 || i == 6 ) B --;
        if( i == 3 || i == 5 ) C --;
        if( A < 0 || B < 0 || C < 0 ) return 0;
        sum --;
        if( sum == 0 ) return 1;
    }

    for( int i = 1; i < num; i ++ )
    {
        if( i == 1 || i == 4 || i == 7 ) A --;
        if( i == 2 || i == 6 ) B --;
        if( i == 3 || i == 5 ) C --;
        if( A < 0 || B < 0 || C < 0 ) return 0;
        sum --;
        if( sum == 0 ) return 1;
    }

}

int Check( ll num )
{
    for( int i = 1; i <= 7; i ++ )
    {
        A = a;
        B = b;
        C = c;
        if( Judge( i, num ) ) return 1;
    }
    return 0;
}

int main()
{
    cin >> a >> b >> c;
    ll weeknum = min( a / 3, min( b / 2, c / 2 ) );
    a -= weeknum * 3;
    b -= weeknum * 2;
    c -= weeknum * 2;
    ll day = 0;
    day += weeknum * 7;
    ll num = 14;
    while( num )
    {
        if( Check( num ) )
        {
            day += num;
            break;
        }
        num --;
    }
    cout << day << endl;
    return 0;
}