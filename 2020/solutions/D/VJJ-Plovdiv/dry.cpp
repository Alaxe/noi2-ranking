#include<iostream>
using namespace std;
int main()
{
    int n,a1,a2,sum=0;
    cin>>n>>a1>>a2;
   int r=0;
    int m[n],max=0,max2;
    for (int i=0;i<n;i++)
    {
       cin>>m[i];
    }
    for (int i=0;i<n;i++)
    {   r=0;
        max=0;
        for (int ii=i+1;ii<n;ii++)
        {   r=0;
            if (m[i]<m[ii]) {sum=sum+(ii-i)*a2*a1*m[i];r=1;i=ii;}

        }

        if (r==0)
        {
            for (int ii=i+1;ii<n;ii++)
            {
                if (m[ii]>max) {max=m[ii];max2=ii;}
            }
        sum=sum+(max2-i)*a2*a1*max;
        i=i+max2-i;
        }
    }
    cout<<sum<<endl;
 }



