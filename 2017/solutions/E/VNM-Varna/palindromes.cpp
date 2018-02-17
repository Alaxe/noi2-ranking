#include<iostream>
using namespace std;
int main()
{
    int n, proizv, c=0, w=1, s, sbor=0;
    cin>>n;
    int b[7],pro[n*n-1];
    for(int i=n; i>=0; i--)
    {
        for(int j=n; j>i; j--)
        {
            proizv=i*j;
            pro[c]=proizv;
            c++;
        }
    }
    for(int a=0; a<c; a++)
    {
        for(int d=0; d<7; d++)
        {
            b[d]=pro[a]/w%10;
            w*=10;
        }
        for(int e=1; e<=7; e++)
        {
            s=b[e-1];
            b[7-(e-1)]=s;
            b[e-1]=b[e-1];
        }
        s=7;
        w=1;
        while(s>=0)
        {
             sbor+=b[s]*w;
             w*=10;
        }
        if(sbor==pro[a]) break;
    }
    cout<<sbor<<endl;
    return 0;
}
