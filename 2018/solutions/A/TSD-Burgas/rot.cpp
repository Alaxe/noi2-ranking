#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
char M[4][10001],ob[10001],otd[10001];
int b,M1[4];
int ch[10000];
int de(int n,int m)
{   if(n==0)return m;
    return de(n-1,m*10);
}
int po(int osn,int st)
{   int pr=1;
    for(int i=0;i<st;i++)pr*=osn;
    return pr;
}
int rot(int a)
{   int i=0,novo=0,br=0;
    while(a>0)
    {   ch[i++]=a%10;
        br++;
        a/=10;
    }
   for(i=0;i<br-1;i++)
   {    novo+=(de(i,10)*ch[i]);
   }
    novo+=ch[br-1];
    return novo;
}
void rotdr(char a[])
{   int br=0,i=0;
    while(a[i]!='\0')
    {   br++;
        i++;
    }
    char c=a[0];
    for(i=1;i<br;i++)a[i-1]=a[i];
    a[br-1]=c;
    strcpy(ob,a);
}
int vdes(char a[1001],int o)
{   int d=0,br=0,i=0,m=0;
    while(a[i]!='\0')
    {   br++;
        i++;
    }
    for(i=br-1;i>=0;i--)
    {   if(a[i]>='0'&&a[i]<='9')
        {   d+=(po(o,m)*((int)(a[i])-(int)('0')));
            m++;
        }
        else if(a[i]>='A'&&a[i]<='F')
        {   d+=(po(o,m)*(((int)(a[i])-(int)'A')+10));
            m++;
        }
    }
    return d;
}
int main()
{   int i,A[4][10001],A1[4],l;
    bool fl;
    cin>>b;
    if(b==10)for(i=0;i<4;i++)cin>>M1[i];
    else for(i=0;i<4;i++)cin>>M[i];
    if(b!=10)for(i=0;i<4;i++)M1[i]=vdes(M[i],b);
    for(i=0;i<4;i++)
    {   fl=0;l=10;
        if(b==10)
        {   while(fl==0&&l<100000)
            {   if((rot(l)-l)==M1[i]){fl=1;A1[i]=l;break;}
                l++;
            }
            if(fl==0)A1[i]=0;
        }
        if(b!=10)
        {


        }

    }
    if(b==10)for(i=0;i<4;i++)cout<<A1[i]<<endl;

    return 0;
}
