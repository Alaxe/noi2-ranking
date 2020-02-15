#include<iostream>
using namespace std;
int main ()
{
    long long N,br=0,ch;
    cin >> N;
    if (N<=9)
    {
        for (ch=1; ch<=N; br++)
        {
            ch++;
        }
        cout << br <<endl;
    }

    else if (N<=99)
    {
        for (ch=11; ch<=N; br++)
        {
            ch=ch+11;
        }
        cout << br+9 <<endl;
    }

    else if (N<=999)
    {
        for (ch=111; ch<=N; br++)
        {
            ch=ch+111;
        }
        cout << br+18 <<endl;
    }

    else if (N<=9999)
    {
        for (ch=1111; ch<=N; br++)
        {
            ch=ch+1111;
        }
        cout << br+27 <<endl;
    }

    else if (N<=99999)
    {
        for (ch=11111; ch<=N; br++)
        {
            ch=ch+11111;
        }
        cout << br+36 <<endl;
    }

    else if (N<=999999)
    {
        for (ch=111111; ch<=N; br++)
        {
            ch=ch+111111;
        }
        cout << br+45 <<endl;
    }

    else if (N<=9999999)
    {
        for (ch=1111111; ch<=N; br++)
        {
            ch=ch+1111111;
        }
        cout << br+54 <<endl;
    }
    else if (N<=99999999)
    {
        for (ch=11111111; ch<=N; br++)
        {
            ch=ch+11111111;
        }
        cout << br+63 <<endl;
    }

    else if (N<=99999999)
    {
        for (ch=11111111; ch<=N; br++)
        {
            ch=ch+11111111;
        }
        cout << br+63 <<endl;
    }

    else if (N<=999999999)
    {
        for (ch=111111111; ch<=N; br++)
        {
            ch=ch+111111111;
        }
        cout << br+72 <<endl;
    }


    else if (N<=9999999999)
    {
        for (ch=1111111111; ch<=N; br++)
        {
            ch=ch+1111111111;
        }
        cout << br+81 <<endl;
    }


    else if (N<=99999999999)
    {
        for (ch=11111111111; ch<=N; br++)
        {
            ch=ch+11111111111;
        }
        cout << br+90 <<endl;
    }


    else if (N<=999999999999)
    {
        for (ch=111111111111; ch<=N; br++)
        {
            ch=ch+111111111111;
        }
        cout << br+99 <<endl;
    }


    else if (N<=9999999999999)
    {
        for (ch=1111111111111; ch<=N; br++)
        {
            ch=ch+1111111111111;
        }
        cout << br+108 <<endl;
    }


    else if (N<=99999999999999)
    {
        for (ch=11111111111111; ch<=N; br++)
        {
            ch=ch+11111111111111;
        }
        cout << br+117 <<endl;
    }

    else if (N<=999999999999999)
    {
        for (ch=111111111111111; ch<=N; br++)
        {
            ch=ch+111111111111111;
        }
        cout << br+126 <<endl;
    }

    else if (N<=9999999999999999)
    {
        for (ch=1111111111111111; ch<=N; br++)
        {
            ch=ch+1111111111111111;
        }
        cout << br+135 <<endl;
    }

    else if (N<=99999999999999999)
    {
        for (ch=11111111111111111; ch<=N; br++)
        {
            ch=ch+11111111111111111;
        }
        cout << br+144 <<endl;
    }

    else if (N<=999999999999999999)
    {
        for (ch=111111111111111111; ch<=N; br++)
        {
            ch=ch+111111111111111111;
        }
        cout << br+153 <<endl;
    }
    return 0;
}
