#include<bits/stdc++.h>
using namespace std;

string str;
int n, goal;
string tmp = "ACTG";

int Check( int x )
{
    int cnt = 0;
    for( int i = 0; i < 4; i ++ )
    {
        auto c = str[ x + i ];
        int val = abs( c - tmp[ i ] );
        cnt += min( val, 26 - val );
    }
    return cnt;
}

int main() {
    cin >> n;
    cin >> str;
    goal = 10000;
    for (int i = 0; i + 3 < n; i++) {
        goal = min(goal, Check(i));
    }
    cout << goal << endl;
    return 0;
}