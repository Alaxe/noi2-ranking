#include<bits/stdc++.h>
using namespace std;

void Output(float n)
{
    long k = n*10000;

    if(k%10>=5)
        k+=10;
    k/=10;
    int zeros = 0;
    if(k%10==0)
    {
        zeros++;

        if((k/10)%10==0)
        {
            zeros++;
            if((k/100)%10==0)
                zeros++;
        }
    }
    n = (float)k/1000;
    cout << n;
    if(zeros==3)
        cout << ".";
    for(int i = 0; i < zeros; i++)
    {
        cout << "0";
    }
}

int main ()
{
    long S, K;
    long a, b, c, d;

    cin >> S >> K >> a >> b >> c >> d;

    long lit = K%(d*4);
    long numOtd = K/(d*4);
    if(lit!=0)
        numOtd++;
    else
    {
        for(int i = 0; i < 4; i++)
            cout << d << ".000" << " ";

        cout << endl;
        return 0;
    }

    long otdType = numOtd%4;

    float otdAnsw[4];

    for(int i = 0; i < 4; i++)
        otdAnsw[i] = 0;

    if(otdType==1)
    {
        //cout << "Type 1" << endl;
        if(lit <= 2*c)
        {
            if(lit >= 2*a)
                otdAnsw[0] = otdAnsw[1] = (float)lit/2;
            else if(lit >= a)
            {
                otdAnsw[0] = a;
                otdAnsw[1] = lit - a;
            }
            else
                otdAnsw[0] = a;
        }
        else if(lit > 2*c && lit <= 4*c)
        {
            otdAnsw[0] = otdAnsw[1] = c;
            lit-=2*c;
            if(lit >= 2*b)
                otdAnsw[2] = otdAnsw[3] = (float)lit/2;
            else if(lit >= b)
            {
                otdAnsw[2] = b;
                otdAnsw[3] = lit - b;
            }
            else otdAnsw[2] = lit;
        }
        else
        {
            otdAnsw[0] = otdAnsw[1] = otdAnsw[2] = otdAnsw[3] = (float)lit/4;
        }
    }
    else if(otdType == 2)
    {
        //cout << "Type 2" << endl;
        if(lit <= b)
            otdAnsw[0] = lit;
        else if(lit > b && lit <= 3*b)
        {
            otdAnsw[0] = b;
            lit -= b;

            if(lit >= 2*a)
                otdAnsw[1] = otdAnsw[2] = (float)lit/2;
            else if(lit >= a)
            {
                otdAnsw[1] = a;
                otdAnsw[2] = lit - a;
            }
            else
                otdAnsw[1] = a;
        }
        else if(lit > 3*b && lit <= 3*c)
        {
            otdAnsw[0] = otdAnsw[1] = otdAnsw[2] = (float)lit/3;
        }
        else if(lit > 3*c && lit <= 4*c)
        {
            otdAnsw[0] = otdAnsw[1] = otdAnsw[2] = (float)lit/3;
            lit -= 3*c;
            otdAnsw[3] = lit;
        }
        else
            otdAnsw[0] = otdAnsw[1] = otdAnsw[2] = otdAnsw[3] = (float)lit/4;
    }
    else if(otdType == 3)
    {
        //cout << "Type 3" << endl;
        if(lit <= 2*c)
        {
            if(lit >= 2*b)
                otdAnsw[0] = otdAnsw[1] = (float)lit/2;
            else if(lit >= b)
            {
                otdAnsw[0] = b;
                otdAnsw[1] = lit - b;
            }
            else
                otdAnsw[0] = b;
        }
        else if(lit > 2*c && lit <= 4*c)
        {
            otdAnsw[0] = otdAnsw[1] = c;
            lit-=2*c;
            if(lit >= 2*a)
                otdAnsw[2] = otdAnsw[3] = (float)lit/2;
            else if(lit >= a)
            {
                otdAnsw[2] = a;
                otdAnsw[3] = lit - a;
            }
            else otdAnsw[2] = lit;
        }
        else
        {
            otdAnsw[0] = otdAnsw[1] = otdAnsw[2] = otdAnsw[3] = (float)lit/4;
        }
    }
    else if(otdType == 0)
    {
        //cout << "Type 4" << endl;
        if(lit <= c)
            otdAnsw[0] = lit;
        else if(lit > c && lit <= c + 2*b)
        {
            otdAnsw[0] = c;
            lit -= c;

            if(lit >= 2*a)
                otdAnsw[1] = otdAnsw[1] = (float)lit/2;
            else if(lit >= a)
            {
                otdAnsw[1] = a;
                otdAnsw[2] = lit - a;
            }
            else
                otdAnsw[1] = a;
        }
        else if(lit > c + 2*b && lit <= c + 3*b)
        {
            otdAnsw[0] = c;
            lit -= c;
            otdAnsw[1] = otdAnsw[2] = a;
            lit-=2*a;
            otdAnsw[3] = lit;
        }
        else if(lit > c + 3*b && lit <= 4*c)
        {
            otdAnsw[0] = c;
            lit -= c;
            otdAnsw[1] = otdAnsw[2] = otdAnsw[3] = (float)lit/3;
        }
        else
            otdAnsw[0] = otdAnsw[1] = otdAnsw[2] = otdAnsw[3] = (float)lit/4;
    }

    Output(otdAnsw[0]);
    cout << " ";
    Output(otdAnsw[1]);
    cout << " ";
    Output(otdAnsw[2]);
    cout << " ";
    Output(otdAnsw[3]);
    cout << endl;

    return 0;
}

