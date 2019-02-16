#include<iostream>
using namespace std;
long long NOK(int x,int y)
{
    int    a=x;
    int    b=y;
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {

            b=b-a;
        }

    }
    return (x/a)*a*(y/a);
}
int main ()
{
    int n,dosega,stepen=2;
    cin>>n;
    int vhod[n];
    for(int a=0; a<n; a++)
    {
        cin>>vhod [a];
    }
    dosega=vhod[0];
    for(int i=1; i<n; i++)
    {
        dosega= NOK(vhod[i],dosega);
    }
    while(true)
    {

        if((stepen*stepen)%dosega==0)
        {
            cout<<stepen;
            break;
        }
        stepen ++;
    }
cout<<endl;
    return 0;
}
