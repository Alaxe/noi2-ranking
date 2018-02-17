#include<iostream>
#include<cmath>
using namespace std;
unsigned long long power[58],t,s,po=1,ks,kt;
int z, a[58][57], otg,br;
bool flag;
int main()
{
    cin>>s>>t>>z;
    if(z>56)
    {
        cout<<0<<endl;
    }
    else if((t-s)<=10000000)
    {

        for(int i=s;i<=t;i++)
        {
            br=0;
            int o=i;
            while(o!=0)
            {
                if(o%2==0)
                {
                    br++;
                    if(br>z) break;
                }
                o/=2;

            }
            if(br==z) otg++;
        }

        cout<<otg<<endl;
    }
    else
    {

        for(int i=1;i<57;i++)
        {
           if(s>=po and s<po*2 and flag==0)
           {
               ks=i;
               flag=1;
           }
           if(t>po)
           {
             power[i]=po*2;
             po*=2;
           }
           else
           {
               kt=i-1;
               power[i]=po*2;
               break;
           }
       }

       for(int i=1;i<=kt;i++)
       {
           a[i][0]=1;
           a[i][1]=i-1;
           a[i][i]=0;
       }
       for(int i=3;i<=kt;i++)
       {
           for(int j=2;j<=i;j++)
           {
               a[i][j]=a[i-1][j]+a[i-1][j-1];

           }
       }
        for(int i=ks;i<=kt;i++)
        {
            otg+=a[i][z];
        }
        cout<<otg<<endl;
    }

    return 0;
}
