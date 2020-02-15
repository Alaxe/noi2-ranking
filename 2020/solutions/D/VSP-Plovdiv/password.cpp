#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    char buk;
    cin>>a;
    int len=a.length(),posl=0,bposl='a';
    buk=a[0];
    for(int i=0; i<len; i++)
    {
        if(buk==a[i])
        {
            posl++;
        }
        else
        {
            buk=a[i];
            posl=0;
        }
        if(bposl>'z')
        {
            bposl='a';
        }
        if(posl>3 or posl==3 or posl>len/2)
        {
            if(bposl==buk)
            {

                a[i]=bposl+1;
            }
            else
            {
                a[i]=bposl;
            }
            bposl++;
            posl=0;
        }
    }
    for(int i=0; i<len; i++)
        cout<<a[i];
    cout<<endl;
}
