#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n;
int row[n];
for(int i=0;i<n;i++)
    {cin>>row[i];}
cin>>m;
int range[m][2];
for(int i=0;i<m;i++)
    {cin>>range[i][0];cin>>range[i][1];}

for(int i=0;i<n-1;i++)
    {
    for(int j=i;j<n;j++)
        {
        if(row[i]>row[j]){swap(row[i],row[j]);}
        }
    }

for(int i=0;i<m;i++)
    {
    for(int j=0;j<n;j++)
        {
        int ans=0;
        if(range[i][0]>row[n-1] || range[i][1]<row[0]){cout<<ans<<endl;break;}
        if(row[j]>=range[i][0])
            {
            while(row[j]<=range[i][1])
                {
                ans++;j++;
                }
            cout<<ans<<endl;
            break;
            }
        }
    }

return 0;
}
