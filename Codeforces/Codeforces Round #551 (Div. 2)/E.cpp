#include<bits/stdc++.h>
using namespace std;


int n, rt;
vector< int > Indexx;
vector< int > Indexy;

int Query( int x1, int y1, int x2, int y2 )
{
    cout<<"? "<< x1 <<' '<< y1 <<" "<< x2 <<' '<< y2 <<endl;
    cin >> rt;
    rt &= 1;
    return rt;
}

void Answer( int x1, int y1, int x2, int y2 )
{
    cout<<"! "<< x1 <<' '<< y1 <<" "<< x2 <<" "<< y2 <<endl;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ) if( Query( i, 1, i, n ) ) Indexx.push_back( i );
    for( int i = 1; i <= n; i ++ ) if( Query( 1, i, n, i ) ) Indexy.push_back( i );

    if( Indexx.size() == 2 && Indexy.size() == 2 )
    {
        if( Query( Indexx[ 0 ], Indexy[ 0 ], Indexx[ 0 ], Indexy[ 0 ] ) )
            Answer( Indexx[ 0 ], Indexy[ 0 ], Indexx[ 1 ], Indexy[ 1 ] );
        else
            Answer( Indexx[ 0 ], Indexy[ 1 ], Indexx[ 1 ], Indexy[ 0 ] );
    }
    else if( Indexx.size() == 2 )
    {
        int l = 1;
        int r = n;
        int goal = 0;
        while( l <= r )
        {
            auto mid = l + r >> 1;
            if( Query( Indexx[ 0 ], 1, Indexx[ 0 ], mid ) )
            {
                goal = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        Answer( Indexx[ 0 ], goal, Indexx[ 1 ], goal );
    }
    else
    {
        int l = 1;
        int r = n;
        int goal = 0;
        while( l <= r )
        {
            auto mid = l + r >> 1;
            if( Query( 1, Indexy[ 0 ], mid, Indexy[ 0 ] ) )
            {
                goal = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        Answer( goal, Indexy[ 0 ], goal, Indexy[ 1 ] );
    }
    return 0;
}