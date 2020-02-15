#include<iostream>
#include<vector>
using namespace std;
int a[100001],b[100001];
int w,k;
int n,m;
pair<int,int> num[2000001];
vector<int> use;
long long res;
int i1,i2;
int main()
{
    ios::sync_with_stdio(false);
    cin>>w>>k;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }

    if(w==2)
    {
        int prev=a[0];
        int br=1;
        for(int i=1; i<n; i++)
        {
            if(a[i]==prev)
            {
                br++;
            }
            else
            {
                if(num[prev].first==0 && br>=k)
                {
                    use.push_back(prev);
                }
                if(br>=k)
                {
                    num[prev].first+=br-k+1;
                }
                br=1;
            }
            prev=a[i];
        }
        if(num[prev].first==0 && br>=k)
        {
            use.push_back(prev);
        }
        if(br>=k)
        {
            num[prev].first+=br-k+1;
        }
        prev=b[0];
        br=1;
        for(int i=1; i<m; i++)
        {
            if(b[i]==prev)
            {
                br++;
            }
            else
            {
                if(br>=k)
                {
                    num[prev].second+=br-k+1;
                }
                br=1;
            }
            prev=b[i];
        }
        if(br>=k)
            num[prev].second+=br-k+1;
        int l=use.size();
        for(int i=0; i<l; i++)
        {
            long long r1=num[ use[i] ].first;
            long long r2=num[ use[i] ].second;
            res+=r1*r2;
        }
    }
    cout<<res<<endl;
    return 0;
}
/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

HEAR MY VOICE THIS IS ODIN CALLING YOU
TIMES HAVE CHANGED I'M A GENTLE GOD
NO MORE WAR JUST DESIGN OF FURNITURE
MASTER OF IKEA

*/
