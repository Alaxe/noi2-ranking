#include<iostream>
using namespace std;
int main()
{
    int w,h,broi;
    cin>>w>>h>>broi;
    int x[broi],y[broi],redove[h];
    for(int j=0;j<h;j++)
    {
        redove[j]=0;
    }
    cin>>x[0]>>y[0];
    for(int i=1;i<broi;i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]==x[i-1])
        {
            for(int z=y[i-1];z<y[i];z++)
            {
                if(x[i]>redove[z]) redove[z]=x[i];
            }
        }
    }
    int sum=0;
    for(int u=0;u<h;u++)
    {
        sum=sum+w-redove[u];
    }
    cout<<sum;
}
