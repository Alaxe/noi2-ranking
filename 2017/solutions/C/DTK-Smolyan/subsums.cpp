#include<iostream>
using namespace std;
int n,sum=0,summas[10000000],brm=0;
short ch[1001];
void intmas(int a)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch[i];
        sum+=ch[i];
    }

}
void prov(int sum1)
{
    bool flag=0;
    for(int i=1;i<n*n;i++)
    {
        if (summas[i]==sum1)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        summas[brm]=sum;
        brm++;
    }
}
int main()
{
    intmas(0);
    for(int i=0;i<n*n;i++)summas[i]=ch[0];
    for(int i=0;i<n;i++)summas[i]=ch[i];
    summas[n]=sum;
    brm=n+1;
    bool f=0;
    for(int i=0;i<n-1;i++)
    {
        sum=ch[i];
        //ot jtoto do ntoto
        for(int j=i+1;j<n;j++) sum+=ch[j];
        prov(sum);

        for(int p=i+1;p<n;p++)
        {
            sum=ch[i];
            for(int j=i+1;j<p;j++)
            {
                sum+=ch[j];
            }
            prov(sum);
        }
        for(int j=i+1;j<n;j++)
        {
            sum=ch[i]+ch[j];
            prov(sum);
        }
        for(int p=i+1;p<n;p++)
        {
            sum=ch[i];
            for(int j=p+1;j<n;j++)
            {
                sum+=ch[j];

            }
            prov(sum);
        }

    }
    int min,minch,br=0;
    for(int i=0;i<n*n-1;i++)
    {
        min=i;
        minch=summas[i];
        for(int j=i+1;j<n*n;j++)
        {
            if(minch>summas[j])
            {
                min=j;
                minch=summas[j];
            }
        }
        swap(summas[min],summas[i]);
    }
    for(int i=0;i<n*n;i++)
    {
        if (summas[i]!=summas[i-1])br=br+1;
    }
    cout<<br;

}
/*
5
1 -2 0 7 7
*/
