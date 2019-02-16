#include<iostream>
#include<algorithm>
using namespace std;
int d[100000];
int n,brm1,br,brm2;
bool mark[100000];

void cont(int i);
int contback(int i);

int main()
{
    int i,j,brm=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>d[i];
    }

    for(i=0; i<n; i++)
    {
        //for(j=0;j<n;j++)mark[j]=1;
        brm1=0;
        brm2=0;
        br=0;
        cont(i);
        br=0;
        contback(i);
        if(brm<brm1+brm2-1)
            brm=brm1+brm2-1;
    }
    cout<<brm<<endl;
    return 0;
}
void cont(int i)
{
    int j;
    br++;
    for(j=i+1;j<n;j++)
    {
        if(d[i]>d[j])
        {
            cont(j);
            br--;
        }
    }
    if(brm1<br)brm1=br;
}
int contback(int i)
{
    int j;
    br++;
    for(j=i-1;j>=0;j--)
    {
        if(d[i]>d[j])
        {
            contback(j);
            br--;
        }
    }
    if(brm2<br)brm2=br;
}
