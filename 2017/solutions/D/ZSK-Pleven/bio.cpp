#include <bits/stdc++.h>
using namespace std;
void d1(int d,int m)
{
    int dni;
    if(m==2)dni=28;
    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)dni=31;
    else if(m==4 || m==6 || m==9 || m==11)dni=30;
    if(d+23>dni)
    {
        m+=1;
        d=23-(dni-25);
    }
}
int main()
{

    return 0;
}
///21252
