#include <iostream>
#include <cmath>
using namespace std;
struct pacient
{
    int mf,fp;
};
pacient g[1024];
int i=0;
double p;
int forcout()
{
    int j;
    for(j=0; j<i-2; j++)
    {
        if((g[j].mf+g[j].fp)>=g[j+1].fp)
        {
            p=g[j+1].fp+((g[j].mf+g[j].fp)-g[j+1].mf);
        }
        else
        {
            if((g[j].mf+g[j].fp)<g[j+1].mf)
            {
                p=g[j+1].fp;
            }
        }
    }
    if(p>189) p-=(g[j+1].fp);
    if(p<0)
    {
        double f=abs(p);
        p=f-1;
    }
    return p;
}
void cmp()
{
    for(int k=0; k<720; k++)
    {
        for(int j=0; j<i-2; j++)
    {
        if(g[j].mf>g[(j+1)].mf)
        {
            swap(g[j].mf,g[(j+1)].mf);
            swap(g[j].fp,g[(j+1)].fp);
        }
    }
    }
}
void read()
{
    while(cin)
    {
        cin>>g[i].mf>>g[i].fp;
        i++;
    }
}
int main()
{
    read();
    cmp();
    cout<<forcout()<<endl;
return 0;
}
