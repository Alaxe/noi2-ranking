#include<iostream>
using namespace std;
int main ( )
{
    long long n;
    int x;
    int ch0=0,ch1=0,ch2=0;
    cin>>n>>x;
    if(x==0)ch0=1;
    else if(x==1)ch1=1;
    else if(x==2)ch2=1;
    int m=1;

    while(m<=n)
    {
        if(m%2==0)
        {
            swap(ch0,ch1);

        }
        else swap(ch1,ch2);
        m++;
    }
    if(ch0==1)cout<<"0";
    else if(ch1==1)cout<<"1";
    else if(ch2==1)cout<<"2";
    return 0;
}
/*
Вход    Вход
4       1
2       1

Изход   Изход
1       0


*/
