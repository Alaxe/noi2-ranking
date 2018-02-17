#include<iostream>
using namespace std;
int b[1001];
void clearB(int n)
{
    for(int i=0;i<n;i++)
    {
        b[i]=0;
    }
}

int BR(int n)
{
    int br=0;
    for(int i=0;i<n;i++)
    {
        br+=b[i];
    }
    return br;
}
int main()
{
    int n,br=0,mina=1001,maxa=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(mina>a[i])mina=a[i];
            if(maxa<a[i])maxa=a[i];
        }

    for(int i=1;i<=maxa-mina;i++)
    {
        clearB(n);
        for(int l=n-2;l>=0;l--)
        {
            for(int r=l+1;r<n;r++)
            {
                //cout<<i<<" "<<l<<" "<<r<<endl;
                if(a[r]-a[l]==i)
                    {
                        b[l]++;
                        b[l]+=b[r];
                        //br+=b[l];
                        //cout<<br<<endl;
                        //cout<<a[r]<<" "<<a[l]<<endl;
                    }
            }
        }
        br+=BR(n);
    }

    cout<<br%123456789012345<<endl;
    return 0;
}
