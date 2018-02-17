#include <iostream>
using namespace std;
int brc (long long a)
{
    int br=0;
    while (a!=0)
    {
        br++;
        a/=10;
    }
    return br;
}
int main()
{
    long long N,L,a=10,b=10,c=10,snum=0,num=0,br,ch,brn,mun;
    bool yn;
    cin>>N;
    cin>>L;
    if (L==1) cin>>a;
    else if (L==2) cin>>a>>b;
    else cin>>a>>b>>c;
    for (long long i=1;i<=N;i++)
    {
        yn=false;
        num=snum+1;
        while (yn==false)
        {
            br=0;
            brn=brc(num);
            mun=num;
            while (brn!=0)
            {
                ch=mun%10;
                if ( L==3 && ch!=a && ch!=b && ch!=c) br++;
                else if (L==2 && ch!=a && ch!=b) br++;
                else if (L==1 && ch!=a) br++;
                else
                {
                    br=0;
                    break;
                }
                brn--;
                mun/=10;
            }
            if (br==0) yn=false,num++;
            else snum=num,yn=true;
        }
    }
    cout<<snum<<endl;
    return 0;
}
