#include<iostream>
#include<string>
using namespace std;
int main( )
{
    int n, i, a, b, c, d, p, br=0;
    string s;
    string k;
    cin >> n;
    a=0;
    b=0;
    c=0;
    d=0;
    for(i=0;i<n;i++)
    {
        cin >> s[i];
    }
    for(i=0;i<n;i++)
    {
        if(s[i] == 'a') a++;
        else if(s[i] == 'b') b++;
        else if(s[i] == 'c') c++;
        else if(s[i] == 'd') d++;
    }
    if(a + b == c + d) cout << n;
    else
    {
        a=0;
        b=0;
        c=0;
        d=0;
        for(i=0;i<n;i++)
        {
            for(p=0;p<=i;p++)
            {
                if(s[p] == 'a') a++;
                else if(s[p] == 'b') b++;
                else if(s[p] == 'c') c++;
                else if(s[p] == 'd') d++;
            }
            if(a + b == c + d) br = a + b + c + d;
            a=0;
            b=0;
            c=0;
            d=0;

        }
        if(br!=0) cout << br;
        else cout << 0;
    }
    cout << endl;
}
