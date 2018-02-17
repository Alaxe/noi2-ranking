#include<iostream>
#include<vector>
using namespace std;
vector <long long> v;
int n,i;
long long w,h,x1,x2,y1,y2,j,sum;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>w>>h;
    cin>>n;
    sum=w*h;
    cin>>x1>>y1;
    for(i=1;i<n;i++)
    {
        cin>>x2>>y2;
        if(x1==x2)
        {
            if(y1<y2)
            {
                while(v.size()<=y2)
                {
                    v.push_back(0);
                }
                for(j=y1+1;j<=y2;j++)
                {
                    if(v[j]<x1)
                    {

                        sum=sum-(x1-v[j]);
                        v[j]=x1;
                    }
                }
            }else
            {
                while(v.size()<=y1)
                {
                    v.push_back(0);
                }
                for(j=y2+1;j<=y1;j++)
                {
                    if(v[j]<x1)
                    {
                        sum=sum-(x1-v[j]);
                        v[j]=x1;
                    }
                }
            }

        }
        x1=x2;
        y1=y2;
    }
    cout<<sum<<'\n';
    return 0;
}
