#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n,u,v;
    cin>>n>>u>>v;
    vector<int>m;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]<m[i-1]&&m[i]<m[i+1])i++;
        if(m[i]>m[i+1]&&m[i+2]>m[i+1])
        {
            n++;

            if(m[i]>m[i+2])
            {
               sum+=n*m[i]*v;
            }
            if(m[i]<m[i+2])
            {
                sum+=n*m[i+2]*v;
            }
            n--;
        }
        else
        {
             if(m[i]>m[i+1])
            {
               sum+=n*m[i]*v;
            }
            else sum+=n*m[i+1]*v;
        }
    }
    cout<<sum<<endl;

return 0;
}
