#include<bits/stdc++.h>
using namespace std;
long long mesec[12],d[4];
long long haha(long long m,long long d)
{
    long long ans=0;
    for(int i=0; i<m; i++)
    {
        ans+=mesec[i];
    }
    ans+=d;
    return ans;
}
int main()
{
    int i1=1;
    mesec[0]=31;
    mesec[2]=31;
    mesec[3]=30;
    mesec[4]=31;
    mesec[5]=30;
    mesec[6]=31;
    mesec[7]=31;
    mesec[8]=30;
    mesec[9]=31;
    mesec[10]=30;
    mesec[11]=31;
    string a;
    int prod;
    long long minDni;
    cin>>a>>prod;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!='/')
        {
            if(a[i+1]=='/' && i1!=3)
            {
                d[i1]+=a[i]-'0';
            }
            else if(a[i+1]!='/' && i1!=3)
            {
                d[i1]+=(a[i]-'0')*10;
            }
            if(i1==3)
            {
                if(i+1==a.size())
                {
                    d[i1]+=a[i]-'0';
                }
                else if(i+2==a.size())
                {
                    d[i1]+=(a[i]-'0')*10;
                }
                else if(i+3==a.size())
                {
                    d[i1]+=(a[i]-'0')*100;
                }
                else if(i+4==a.size())
                {
                    d[i1]+=(a[i]-'0')*1000;
                }
            }
        }
        else
        {
            i1++;
        }
    }
    if(d[3]!=2020)
    {
        mesec[1]=28;
    }
    else
    {
        mesec[1]=29;
    }
    minDni=haha(d[2]-1,d[1]);
    while(true){
        if(minDni%7!=3 && minDni%7!=4){
            d[1]++;
            minDni++;
            prod--;
        }else{
            d[1]++;
            minDni++;
        }
        if(d[1]>mesec[d[2]-1]){
            d[2]++;
            d[1]=1;
        }
        if(d[2]>12){
            d[3]++;
            d[2]=1;
        }
        if(prod==0){
            break;
        }
    }
    if(d[1]<10){
        cout<<0<<d[1]<<".";
    }else{
        cout<<d[1]<<".";
    }
    if(d[2]<10){
        cout<<0<<d[2]<<".";
    }else{
        cout<<d[2]<<".";
    }
    cout<<d[3]<<"\n";
    return 0;
}
