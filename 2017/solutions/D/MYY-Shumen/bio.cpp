#include <iostream>
using namespace std;
int d[16];
int sum[16];
int date[4];
int x=1<<10-1;
int main()
{
    string aa,bb,cc,dd;
    cin>>aa>>bb>>cc>>dd;
    d[0]=31;
    d[1]=28;
    d[2]=31;
    d[3]=30;
    d[4]=31;
    d[5]=30;
    d[6]=31;
    d[7]=31;
    d[8]=30;
    d[9]=31;
    d[10]=30;
    d[11]=31;
    int i;
    for (i=1;i<=12;i++)
    {
        sum[i]=sum[i-1]+d[i-2];
    }
    int num1=0,num2=0;
    int sz1=aa.size();
    int sz2=bb.size();
    int sz3=cc.size();
    int sz4=dd.size();
    for (i=0;aa[i]!='/';i++)
    {
        num1=num1*10+(aa[i]-'0');
    }
    i++;
    while (i<sz1)
    {
        num2=num2*10+(aa[i]-'0');
        i++;
    }
    //cout<<num1<<" "<<num2<<endl;
    date[0]=num1+sum[num2];
    num1=0;num2=0;
    for (i=0;bb[i]!='/';i++)
    {
        num1=num1*10+(bb[i]-'0');
    }
    i++;
    while (i<sz2)
    {
        num2=num2*10+(bb[i]-'0');
        i++;
    }
    date[1]=num1+sum[num2];
    num1=0;num2=0;
    for (i=0;cc[i]!='/';i++)
    {
        num1=num1*10+(cc[i]-'0');
    }
    i++;
    while (i<sz3)
    {
        num2=num2*10+(cc[i]-'0');
        i++;
    }
    date[2]=num1+sum[num2];
    num1=0;num2=0;
    for (i=0;dd[i]!='/';i++)
    {
        num1=num1*10+(dd[i]-'0');
    }
    i++;
    while (i<sz4)
    {
        num2=num2*10+(dd[i]-'0');
        i++;
    }
    date[3]=num1+sum[num2];
    //cout<<date[0]<<" "<<date[1]<<" "<<date[2]<<" "<<date[3]<<endl;
    int j;
    for (j=date[3]+1;;j++)
    {
        int h1=j-date[0];
        int h2=j-date[1];
        int h3=j-date[2];
        if (h1%23==0&&h2%28==0&&h3%33==0)
        {
            cout<<j-date[3]<<endl;
            return 0;
        }
    }
return 0;
}
