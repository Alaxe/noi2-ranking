#include <iostream>
using namespace std;
struct data
{
    int d;
    char c;
    int m;
    void read();
} a;
data f[4];
int x[4];
long long br=0;
long long forcout()
{
    do
    {
        br++;
        x[0]+=23;
        if(x[0]==x[1] && x[1]==x[2]) break;
        x[1]+=28;
        if(x[0]==x[1] && x[1]==x[2]) break;
        x[2]+=33;
        if(x[0]==x[1] && x[1]==x[2]) break;
    }while(x[0]!=x[1] && x[1]!=x[2]);
    return br;
}
void data::read()
{
    for(int i=0; i<4; i++)
    {
        cin>>f[i].d>>f[i].c>>f[i].m;
    }
}
void change()
{
    int p;
    int p1=1;
    for(int i=0; i<4; i++)
    {
            if(f[i].m-1==1 || f[i].m-1==3 || f[i].m-1==5 || f[i].m-1==7 || f[i].m-1==8 ||f[i].m-1==10 ||f[i].m-1==12) p1=31;
            else
            {
                if(f[i].m-1!=2) p1=30;
                else p1=28;
            }
            p1*=(f[i].m-1);
            x[i]=f[i].d+p1;
    }
}

int main()
{
    a.read();
    change();
    cout<<forcout()<<endl;
return 0;
}
