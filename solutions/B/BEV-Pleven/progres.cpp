#include<iostream>
#include<vector>


using namespace std;
void cleaner();
vector<pair<int, int> > v[1023];
int mas[1023],dis[1023],dipi[1023];
int n,ans;
void rec(int x, int y)
{
    cout<<x<<" "<<y<<endl;
    for(int i=0; i<v[x].size(); i++)
    {
        int k=v[x][i].first;
        int val=v[x][i].second;
        if(y==0&&val>0)
        {
            //cout<<1<<endl;
            rec(k,val);
            ans++;
        }
        else if(mas[i]>mas[x])
            if(val==y)
            {
                //cout<<val<<endl;
                rec(k,val);
                ans++;
            }
    }
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>mas[i];
    }
    for(int i=1; i<=n; i++)
    {
        //cleaner();
        for(int j=i+1; j<=n; j++)
        {
            if(mas[j]>mas[i])
            {

                v[i].push_back(make_pair(j,mas[j]-mas[i]));
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        rec(i,0);
    }
    cout<<ans<<endl;
}

void cleaner()
{
    for(int i=1; i<=n; i++)
    {
        dipi[i]=0;
        dis[i]=0;
    }
}
