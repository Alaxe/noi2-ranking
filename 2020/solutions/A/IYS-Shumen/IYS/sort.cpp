#include<bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1<<17);
const long long INF = (1e10);
int arr[MAXN],a[MAXN],ans,n;
void read()
{
    int i,j,x,y,z;
    long long cnt=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=1; i<n-1; i++)
    {
        if(arr[i]>arr[i+1]||arr[i]<arr[i-1])
            cnt++;
    }
    for(i=1; i<n; i++)
        a[i-1]=arr[i]-arr[i-1];
    if(cnt==0)
    {
        cout<<0<<endl;
        exit(0);
    }
    if(cnt==2)
    {
        for(i=1; i<n-1; i++)
        {
            if(arr[i]<arr[i-1])
                ans=arr[i-1]-arr[i];
            else if(arr[i]>arr[i+1])
                ans=arr[i]-arr[i+1];
            else
                continue;
            cout<<ans<<endl;
            exit(0);
        }

    }
    long long mm=0,id=0,tek,l;
    for(i=0; i<n; i++)
    {
        mm=INF;
        if(a[i]<0)
        {
            //cout<<i<<" "<<a[i]<<endl;
            //cout<<i<<" - > \n";
            x=-a[i];
            for(j=0; j<=x; j++)
            {
                tek=0;
                y=j;
                for(l=i-1; l>=0; l--)
                {
                    tek+=y;
                    if(a[l]>0)
                        y-=a[l];
                    if(y<=0)
                        break;
                }

                y=x-j;

                for(l=i+1; l<n; l++)
                {
                    tek+=y;
                    if(a[l]>0)
                        y-=a[l];
                    if(y<=0)
                        break;
                }

                if(tek<mm)
                {
                    mm=tek;
                    id=j;
                }
                //cout<<j<<" "<<tek<<endl;
            }
            //cout<<id<<endl;
            y=id;
            //cout<<"index ";
            j=0;
            for(j=i-1; j>=0; j--)
            {
                ans+=y;
                //cout<<j<<" ";
                if(a[j]>0)
                {
                    if(y>a[j])
                    {
                        y-=a[j];
                        a[j]=0;
                    }
                    else
                    {
                        a[j]-=y;
                        y=0;
                        break;
                    }
                }
            }
            if(j<=0)ans+=y;
            y=x-id;
            j=n-2;
            for(j=i+1; j<n-1; j++)
            {
                ans+=y;
                //cout<<j<<" ";
                if(a[j]>0)
                {
                    if(y>a[j])
                    {
                        y-=a[j];
                        a[j]=0;
                    }
                    else
                    {
                        a[j]-=y;
                        y=0;
                        break;
                    }
                }
            }
            if(j>=n-2)ans+=y;
            //cout<<endl;
            a[i]=0;

        }
    }
    cout<<ans<<endl;
    /*for(i=1;i<n;i++)
    {
        a[i-1]=arr[i]-arr[i-1];
    }
    int tek=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]<0)
        {
            y=z=100000;
            if(i)y=a[i-1];if(y<0)y=0;
            if(i!=n-2)z=a[i+1];if(z<0)z=0;
            x=-a[i];
            ans+=min(y,x);
            x-=min(y,x);

            ans+=x;

            a[i]=0;
            a[i+1]-=x;
        }
    }
    cout<<ans<<endl;*/
}
int main()
{
    read();
    return 0;
}
