#include<iostream>
using namespace std;
int s,a[1001],b[1001],maxs=0,n,i,j,k,t1,t2,t3,t4,t5,t6,br=0,maxj=0,maxi=0;
int main ()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        a[i]+=i;
    }
    for(j=1;j<=n;j++)
    {
        b[j]+=j;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {b[i]+=i;
            s=a[i]*b[j];

        k=s;
        while(k>0)
        {
            br++;
            k=k/10;
        }
        if(br=1 && s>maxs)
        {
            maxs=s;
            maxi=a[i];
            maxj=b[j];
        }
        else if(br==2)
        {
            t1=s/10;
            t2=s%10;
            if(s>maxs && t1==t2)
            {
                maxs=s;
                maxi=a[i];
                maxj=b[j];
            }
        }
        else if(br==3)
        {
            t1=s/100;
            t2=(s/10)%10;
            t3=s%10;
            if(s>maxs && t1==t3)
            {
                maxs=s;
                maxi=a[i];
                maxj=b[j];
            }
        }
        else if(br==4)
        {
            t1=s/1000;
            t2=(s/100)%10;
            t3=(s/10)%10;
            t4=s%10;
            if(s>maxs && t1==t4 && t2==t3)
            {
                maxs=s;
                maxi=a[i];
                maxj=b[j];
            }
        }
        else if(br==5)
        {
            t1=s/10000;
            t2=(s/1000)%10;
            t3=(s/100)%10;
            t4=(s/10)%10;
            t5=s%10;
            if(s>maxs && t1==t5 && t2==t4)
            {
                maxs=s;
                maxi=a[i];
                maxj=b[j];
            }

        }
        else if(br==6)
        {
            t1=s/100000;
            t2=(s/10000)%10;
            t3=(s/1000)%10;
            t4=(s/100)%10;
            t5=(s/10)%10;
            t6=s%10;
            if(s>maxs && t1==t6 && t2==t5 && t3==t4)
            {
                maxs=s;
                maxi=a[i];
                maxj=b[j];
            }
        }
    }br=0;}
//cout<<maxi<<" "<<maxj<<" "<<maxs<<endl;
    cout<<min(maxi,maxj)<<" "<<max(maxi,maxj)<<endl<<maxs<<endl;




    return 0;
}
