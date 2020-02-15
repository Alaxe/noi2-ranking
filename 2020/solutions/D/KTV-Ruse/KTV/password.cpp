#include<iostream>
#include<string.h>
using namespace std;
char a[5001];
int main()
{
    long long n,j,br=0,h,l,br1=0;
    double f;
    char c;
    cin>>a;
    n=strlen(a);
    for(h=0;h<n;h++)
    {
        c=a[h];
        for(l=0;l<n;l++)
        { 
            if(a[l]==c) br++;                              
        }
        br++;
        f=br/3;
        if(f>0)
        for(j=h+1;j<n;j++)
        {
            if(a[j]==c) br++;
            if(br%3==0) {a[j]=c+1;br1++;}
        }
        if((br+1-br1)>n/2)
        {
            a[h]=(c+1);
        }
        br=0;
        br1=0;
    }
    cout<<a<<endl;
    return 0;
}