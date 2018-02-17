#include <iostream>
#include <string>

using namespace std;

string s;
int i ,l ,a ,b ;
bool flag = 0 ;

int main()
{
    cin >> s ;
    l = s.size();
    int i = (l/2-1) , j ;

    if ( l%2 == 0 ) j = l/2 ;
    else j = (l/2) + 1 ;

    for ( ; i >= 0 ; i -- , j ++ )
    {
        a = s[i] - '0' ;
        b = s[j] - '0' ;

        if( flag == 0  )
        {
            if( a <= b ) a ++ ;
            b = a ;
            s[i] = s[j] = a + '0' ;
            flag = 1;
        }
        else
            s[j] = s[i] ;
    }
    cout << s << endl;
}
