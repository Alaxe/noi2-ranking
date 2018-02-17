#include<iostream>
#include<vector>
using namespace std;
vector<long long> rss;
vector<long> used[100004];
bool check(long point , int color)
{
    for(long i=0;i<used[point].size();i++)
    {
        if(used[point][i]==color)
        {
            return false;
        }
    }
    return true;
}
void test()
{
    for(long i=0;i<100000;i++)
    {
        used[i].clear();
    }
    int colors=2;
    long n,tek;
    vector<long> vhod;
    cin>>n;
    for(long i=0;i<n;i++)
    {
        cin>>tek;
        vhod.push_back(tek-1);
    }
    for(long i=0;i<n;i++)
    {
        bool k=false;
        for(int j=1;j<=colors;j++)
        {
              if((k==false)&&((check(i,j)&&check(vhod[i],j))))
              {
                  //cout<<"making "<<i<<" to "<<vhod[i]<<" in color"<<j<<endl;
                  k=true;
                  used[i].push_back(j);
                  used[vhod[i]].push_back(j);
              }
        }
        if(k==false)
        {
            colors++;
            used[i].push_back(colors);
            used[vhod[i]].push_back(colors);
            //cout<<"making "<<i<<" to "<<vhod[i]<<" in color"<<colors<<endl;
        }
    }
    rss.push_back(colors);
}
int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        test();
    }
    for(int i=0;i<t;i++)
    {
        cout<<rss[i]<<endl;
    }
}

///69 reda
