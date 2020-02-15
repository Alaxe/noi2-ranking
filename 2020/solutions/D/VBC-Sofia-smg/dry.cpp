#include<iostream>
using namespace std;
int main()
{
    long long n, u, v, steni[100], nai_g, Nomer, nai_g_seg, Nomer_seg, voda=0;
    cin>>n>>u>>v;
    bool l[n]={true}, r[n]={false}, ok=false;
    r[n-1]=true;
    for(long long i=0;i<n;i++)
    {
        cin>>steni[i];
    }
    while(!ok)
    {
        nai_g=0;
        for(int i=0;i<n;i++)
        {
            if(nai_g<steni[i] && (!r[i] || !l[i]))
            {
                nai_g=steni[i];
                Nomer=i;
            }
        }
        if(!l[Nomer])
        {
            nai_g_seg=0;
            for(int i=0;i<Nomer;i++)
            {
                if(nai_g_seg<steni[i] && !r[n])
                {
                    nai_g_seg=steni[i];
                    Nomer_seg=i;
                }
            }
            if(nai_g_seg>nai_g)
            {
                voda=voda+((Nomer-Nomer_seg)*u)*v*nai_g;
            }
            else
            {
                voda=voda+((Nomer-Nomer_seg)*u)*v*nai_g_seg;
            }
            for(int i=Nomer_seg;i<Nomer;i++)
            {
                r[i]=true;
                l[i+1]=true;
            }
        }
        if(!r[Nomer])
        {
            nai_g_seg=0;
            for(int i=Nomer+1;i<n;i++)
            {
                if(nai_g_seg<steni[i] && !l[n])
                {
                    nai_g_seg=steni[i];
                    Nomer_seg=i;
                }
            }
            if(nai_g_seg>nai_g)
            {
                voda=voda+((Nomer_seg-Nomer)*u)*v*nai_g;
            }
            else
            {
                voda=voda+((Nomer_seg-Nomer)*u)*v*nai_g_seg;
            }
            for(int i=Nomer;i<Nomer_seg;i++)
            {
                r[i]=true;
                l[i+1]=true;
            }
        }
        ok=true;
        for(int i=0;i<n;i++)
        {
            if(!l[i] || !r[i])
            {
                ok=false;
                break;
            }
        }
    }
    cout<<voda<<endl;
    return 0;
}
