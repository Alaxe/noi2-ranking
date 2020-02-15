#include<iostream>
using namespace std;
int main()
{
    int n = 0, i = 0, a = 0, b = 0, c = 0, d = 0;
    string ball;
    cin >> n;
    cin >> ball;
    for(i = 0; i <= n; i++)
    {
        if(ball[i] == 'a') a++;
        else if(ball[i] == 'b') b++;
        else if(ball[i] == 'c') c++;
        else if(ball[i] == 'd') d++;
    }
    if(a == 0) cout << 0 << endl;
    else
    {
        if(b == 0) cout << 0 << endl;
        else
        {
            if(c == 0) cout << 0 << endl;
            else
            {
                if(d == 0) cout << 0 << endl;
                else
                {
                    if(a + b == c + d)
                    {
                        cout << a + b + c + d << endl;
                    }
                    if(a + b > c + d)
                    {
                        cout << c + d + c + d << endl;
                    }
                    if(a + b < c + d)
                    {
                        cout << a + b + a + b << endl;
                    }
                }
            }
        }
    }
    return 0;
}
