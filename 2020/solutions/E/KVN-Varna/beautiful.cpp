#include<iostream>
using namespace std;
int main ( )
{
    long long n;
    cin>>n;
    int broi=0;
    int ch=1;
    if(n>9)broi=broi+9;
    else broi=broi+n;
    while(ch<=n)
    {
        if(ch%11==0)broi++;
    }
    cout<<broi;


    return 0;
}
/*
Вход
30

Изход
11

*/
