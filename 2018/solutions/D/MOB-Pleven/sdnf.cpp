#include<iostream>
#include<cstdio>
using namespace std;
string s;
int umn(int n)
{
    string l;
    l="";
    while(n!=0)
    {
        l+=n%10+48;
        n/=10;
    }
    string k="";
    for(int i=0; i<l.size()+s.size(); i++)k+="0";
    int divumn=0;
    int h=0;
    int x,y;
    int z;
    for(int i=0; i<l.size(); i++)
    {
        h=i;
        x=l[i]-48;
        for(int j=0; j<s.size(); j++)
        {
            y=s[j]-48;
            z=x*y+divumn;
            divumn=z/10;
            z%=10;
            k[h]+=z;
            if(k[h]>'9')
            {
                k[h+1]+=(k[h]-48)/10;
                k[h]=(k[h]-48)%10+48;
            }
            h++;
        }
        if(divumn>0)k[h]+=divumn;
        if(k[h]>'9')
        {
            k[h+1]+=(k[h]-48)/10;
            k[h]=(k[h]-48)%10+48;
        }
        divumn=0;
    }
    s=k;
}
int main()
{
    int counter=0;
    int n;
    scanf("%d",&n);
    s="1";
    int j=0;
    int p=1;
    for(int i=1; i<=n; i++)
    {
        j=i;
        umn(j);
    }
    for(j=0; j<s.size(); j++)
    {
        counter+=s[j]-48;
    }
    printf("%d",counter);
    return 0;
}
