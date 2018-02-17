#include <iostream>
using namespace std;
int d(unsigned long long z)
{int l=0;
    while(z!=0)
    {
        l++;
        z=z/10;
    }
    return l;

return 0;
}
unsigned long long rev(unsigned long long x)
{unsigned long long z=0;
    while(x!=0)
    {
        z+=x%10;
        z=z*10;
        x=x/10;
    }
    z=z/10;
    return z;
}
int prov(unsigned long long x1,unsigned long long y1,int z1)
{int br=0;
    if(z1%2 == 0)
    {
       for(int i=0;i<z1/2;i++)
       {
           if(x1%10 == y1%10)br++;
           x1=x1/10;
           y1=y1/10;
       }
       if(br==z1/2)return 1;
    }
    if(z1%2 != 0)
    {
       for(int i=0;i<z1/2;i++)
       {
           if(x1%10 == y1%10)br++;
           x1=x1/10;
           y1=y1/10;
       }
       if(br==z1/2)return 1;
    }
}
int main ()
{unsigned long long a,b;
int n,k=0,l=0;
cin>>a;
n=d(a);
b=rev(a);
while(l==0)
{
 if(prov(a,rev(a),d(a))==1){cout<<a<<endl;break;}
 else a=a+1;
}


return 0;
}
