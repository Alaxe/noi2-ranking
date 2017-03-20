#include  <bits/stdc++.h>
using  namespace  std;

int main()
{
    ios_base::sync_with_stdio(false);
    int d,m;
    char ch;
    cin>>d>>ch>>m;
    if(m==2)d+=31;
    else if(m==3)d+=59;
    else if(m==4)d+=90;
    else if(m==5)d+=120;
    else if(m==6)d+=151;
    else if(m==7)d+=181;
    else if(m==8)d+=212;
    else if(m==9)d+=243;
    else if(m==10)d+=273;
    else if(m==11)d+=304;
    else if(m==12)d+=334;
    int f=d;
    cin>>d>>ch>>m;
    if(m==2)d+=31;
    else if(m==3)d+=59;
    else if(m==4)d+=90;
    else if(m==5)d+=120;
    else if(m==6)d+=151;
    else if(m==7)d+=181;
    else if(m==8)d+=212;
    else if(m==9)d+=243;
    else if(m==10)d+=273;
    else if(m==11)d+=304;
    else if(m==12)d+=334;
    int e=d;
    cin>>d>>ch>>m;
    if(m==2)d+=31;
    else if(m==3)d+=59;
    else if(m==4)d+=90;
    else if(m==5)d+=120;
    else if(m==6)d+=151;
    else if(m==7)d+=181;
    else if(m==8)d+=212;
    else if(m==9)d+=243;
    else if(m==10)d+=273;
    else if(m==11)d+=304;
    else if(m==12)d+=334;
    int i=d;
    cin>>d>>ch>>m;
    if(m==2)d+=31;
    else if(m==3)d+=59;
    else if(m==4)d+=90;
    else if(m==5)d+=120;
    else if(m==6)d+=151;
    else if(m==7)d+=181;
    else if(m==8)d+=212;
    else if(m==9)d+=243;
    else if(m==10)d+=273;
    else if(m==11)d+=304;
    else if(m==12)d+=334;
    int tek=d;
    if(f==e && f==i && e==i){cout<<21252-tek+1<<'\n';return 0;}
    do
    {
        if(f<e && f<i)
        {
            f+=23;
        }
        else if(e<f && e<i)
        {
            e+=28;
        }
        else if(i<e && i<f)
        {
            i+=33;
        }
    }
    while(f!=e && f!=i && e!=i);
        if(f==e)
        {
            while(f!=i)
            {
                if(i<f)
                while(i<f){
                i+=33;
                }
                else f+=23*28;
            }
        cout<<f-tek+28*23<<'\n';
        }
        else if(f==i)
        {
            while(f!=e)
            {
                if(e<f)
                while(e<f){
                e+=28;
                }
                else f+=23*33;
            }
        cout<<e-tek+33*23<<'\n';
        }
        else if(i==e)
        {
            while(i!=f)
            {
                if(f<i)
                while(f<i){
                f+=23;
                }
                else i+=33*28;
            }
        cout<<i-tek+23*28<<'\n';
        }
    return 0;
}
/*
23/7 26/10 23/7 10/2
*/
