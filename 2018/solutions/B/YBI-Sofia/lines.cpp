#include<iostream>
#include<vector>
using namespace std;
int ori(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return (x1+x2)*(y1-y2)+(x2+x3)*(y2-y3)+(x3+x1)*(y3-y1);
}
bool checked[1024][1024];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    int res=0;
    cin>>n;
    vector<pair<int,int>> vhod;
    int curr1,curr2;
    for(int i=0;i<n;i++)
    {
        cin>>curr1>>curr2;
        vhod.push_back(make_pair(curr1,curr2));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(checked[i][j]==1)
            {
                continue;
            }
            checked[i][j]=1;
            checked[j][i]=1;
            vector<int>rem;
            for(int k=0;k<n;k++)
            {
                if(k==i or k==j or (checked[i][k]==1))
                {
                    continue;
                }
                if(0==ori(vhod[i].first,vhod[i].second,vhod[j].first,vhod[j].second,vhod[k].first,vhod[k].second))
                {
                    for(int h=0;h<rem.size();h++)
                    {
                        checked[rem[h]][k]=1;
                        checked[k][rem[h]]=1;
                    }
                    rem.push_back(k);
                }
            }
            if(res<(2+rem.size()))
            {
                res=2+rem.size();
            }
        }
    }
    cout<<res<<endl;
}
