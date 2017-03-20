#include <iostream>
#include <string>
#include <vector>
#define MAXSTEP 1024
using namespace std;

vector <string> v;
string c;

string mult ( string s , long long p )
{
    int pr=0 ,m , d=s.size();
    string ans = "";

    for( int i = d-1 ; i >= 0 ; i -- )
    {
        m = ((s[i]-'0') * p + pr)%10 ;
        pr = ((s[i] - '0') * p + pr )/10 ;
        ans = (char)(m + '0') + ans ;
    }
    while( pr )
    {
        m = pr%10;
        ans = (char)(m + '0') + ans;
        pr /= 10 ;
    }
    return ans;
}
void init()
{
    v.push_back("2");
    for( int i = 1 ; i <= MAXSTEP ; i ++ )
        v.push_back(mult( v[i-1] , 2 ));
}
void solve()
{
    int l=c.size() ,t=0 ,sum=0 ;

    while( l >= sum )
    {

        sum += v[t].size();
        t ++;
    }
    cout << t-1 << endl;
}
int main()
{
    cin >> c ;
    init() ;
    solve() ;
}
